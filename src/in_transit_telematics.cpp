#include "in_transit_telematics.h"
#include <iostream>
#include <iomanip>
#include <cmath>

// Approximate conversion: 1 degree of latitude/longitude ~ 111.0 km
static const double KM_PER_DEGREE = 111.0;

InTransitTelematics::InTransitTelematics(const std::string& tripID,
                                         const std::string& driverID,
                                         const std::string& passengerID,
                                         GPSCoordinate start,
                                         GPSCoordinate dest,
                                         double speedLimit)
    : tripID(tripID),
      driverID(driverID),
      passengerID(passengerID),
      startLocation(start),
      currentLocation(start),
      destination(dest),
      status(TripStatus::NOT_STARTED),
      currentSpeedKmh(0.0),
      maxSpeedKmh(0.0),
      speedLimitKmh(speedLimit),
      totalDistanceTraveledKm(0.0),
      totalDurationSec(0.0),
      speedingWarnings(0),
      harshBrakingEvents(0),
      sosTriggered(false) {}

double InTransitTelematics::calculateDistanceKm(const GPSCoordinate& p1, const GPSCoordinate& p2) const {
    double dLat = (p2.latitude - p1.latitude) * KM_PER_DEGREE;
    double dLon = (p2.longitude - p1.longitude) * KM_PER_DEGREE;
    return std::sqrt(dLat * dLat + dLon * dLon);
}

void InTransitTelematics::startTrip() {
    if (status == TripStatus::NOT_STARTED) {
        status = TripStatus::IN_PROGRESS;
        std::cout << "[Telematics] Trip " << tripID << " started.\n";
    }
}

void InTransitTelematics::pauseTrip() {
    if (status == TripStatus::IN_PROGRESS) {
        status = TripStatus::PAUSED;
        currentSpeedKmh = 0.0;
        std::cout << "[Telematics] Trip " << tripID << " paused.\n";
    }
}

void InTransitTelematics::resumeTrip() {
    if (status == TripStatus::PAUSED) {
        status = TripStatus::IN_PROGRESS;
        std::cout << "[Telematics] Trip " << tripID << " resumed.\n";
    }
}

void InTransitTelematics::endTrip() {
    if (status == TripStatus::IN_PROGRESS || status == TripStatus::PAUSED) {
        status = TripStatus::COMPLETED;
        currentSpeedKmh = 0.0;
        std::cout << "[Telematics] Trip " << tripID << " completed.\n";
    }
}

void InTransitTelematics::triggerSOS() {
    sosTriggered = true;
    status = TripStatus::EMERGENCY_STOP;
    currentSpeedKmh = 0.0;
    std::cout << "\n[ALERT] EMERGENCY SOS TRIGGERED for Trip " << tripID
              << " at (" << currentLocation.latitude << ", "
              << currentLocation.longitude << ")! Notifying authorities...\n\n";
}

void InTransitTelematics::updateTelemetry(GPSCoordinate newLocation, double newSpeedKmh, double elapsedSec) {
    if (status != TripStatus::IN_PROGRESS) {
        std::cout << "[Telematics] Cannot update telemetry: Trip is not in progress.\n";
        return;
    }

    std::string alert = "None";

    // Calculate distance covered in this interval
    double stepDistance = calculateDistanceKm(currentLocation, newLocation);
    totalDistanceTraveledKm += stepDistance;
    totalDurationSec += elapsedSec;

    // Detect harsh braking (speed drop > 30 km/h in a single update)
    if (currentSpeedKmh - newSpeedKmh > 30.0) {
        harshBrakingEvents++;
        alert = "Harsh Braking Detected";
        std::cout << "[WARNING] Harsh braking detected! Speed dropped from "
                  << currentSpeedKmh << " to " << newSpeedKmh << " km/h.\n";
    }

    // Detect speeding
    if (newSpeedKmh > speedLimitKmh) {
        speedingWarnings++;
        alert = (alert == "None") ? "Overspeeding" : alert + " & Overspeeding";
        std::cout << "[WARNING] Overspeeding! Current speed: " << newSpeedKmh
                  << " km/h (Limit: " << speedLimitKmh << " km/h).\n";
    }

    // Update current state
    currentLocation = newLocation;
    currentSpeedKmh = newSpeedKmh;
    if (newSpeedKmh > maxSpeedKmh) {
        maxSpeedKmh = newSpeedKmh;
    }

    // Save to log
    logs.push_back({totalDurationSec, currentLocation, currentSpeedKmh, alert});
}

double InTransitTelematics::getRemainingDistanceKm() const {
    return calculateDistanceKm(currentLocation, destination);
}

double InTransitTelematics::getEstimatedTimeOfArrivalMin() const {
    double remainingKm = getRemainingDistanceKm();
    if (currentSpeedKmh <= 1.0) {
        return -1.0; // Vehicle stopped or moving too slowly to estimate
    }
    return (remainingKm / currentSpeedKmh) * 60.0;
}

double InTransitTelematics::getAverageSpeedKmh() const {
    if (totalDurationSec <= 0.0) return 0.0;
    return totalDistanceTraveledKm / (totalDurationSec / 3600.0);
}

std::string InTransitTelematics::getStatusString() const {
    switch (status) {
        case TripStatus::NOT_STARTED:    return "Not Started";
        case TripStatus::IN_PROGRESS:    return "In Progress";
        case TripStatus::PAUSED:         return "Paused";
        case TripStatus::COMPLETED:      return "Completed";
        case TripStatus::EMERGENCY_STOP: return "Emergency Stop";
        default:                         return "Unknown";
    }
}

std::string InTransitTelematics::getTripID() const { return tripID; }
double InTransitTelematics::getTotalDistanceTraveledKm() const { return totalDistanceTraveledKm; }
double InTransitTelematics::getTotalDurationSec() const { return totalDurationSec; }
int InTransitTelematics::getSpeedingWarnings() const { return speedingWarnings; }
int InTransitTelematics::getHarshBrakingEvents() const { return harshBrakingEvents; }
bool InTransitTelematics::isSOSTriggered() const { return sosTriggered; }

void InTransitTelematics::displayLiveDashboard() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "----------------------------------------\n";
    std::cout << " LIVE TELEMATICS DASHBOARD (" << tripID << ")\n";
    std::cout << "----------------------------------------\n";
    std::cout << " Status             : " << getStatusString() << "\n";
    std::cout << " Current Location   : (" << currentLocation.latitude << ", " << currentLocation.longitude << ")\n";
    std::cout << " Current Speed      : " << currentSpeedKmh << " km/h\n";
    std::cout << " Distance Traveled  : " << totalDistanceTraveledKm << " km\n";
    std::cout << " Remaining Distance : " << getRemainingDistanceKm() << " km\n";

    double eta = getEstimatedTimeOfArrivalMin();
    if (eta >= 0) {
        std::cout << " Estimated ETA      : " << eta << " mins\n";
    } else {
        std::cout << " Estimated ETA      : Calculating (Vehicle Stopped)\n";
    }
    std::cout << "----------------------------------------\n";
}

void InTransitTelematics::displayTripSummary() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n========================================\n";
    std::cout << "      IN-TRANSIT TELEMATICS SUMMARY     \n";
    std::cout << "========================================\n";
    std::cout << " Trip ID            : " << tripID << "\n";
    std::cout << " Driver ID          : " << driverID << "\n";
    std::cout << " Passenger ID       : " << passengerID << "\n";
    std::cout << " Final Status       : " << getStatusString() << "\n";
    std::cout << " Total Distance     : " << totalDistanceTraveledKm << " km\n";
    std::cout << " Total Duration     : " << (totalDurationSec / 60.0) << " mins\n";
    std::cout << " Average Speed      : " << getAverageSpeedKmh() << " km/h\n";
    std::cout << " Max Speed Recorded : " << maxSpeedKmh << " km/h\n";
    std::cout << " Speeding Warnings  : " << speedingWarnings << "\n";
    std::cout << " Harsh Braking      : " << harshBrakingEvents << "\n";
    std::cout << " SOS Triggered      : " << (sosTriggered ? "YES" : "NO") << "\n";
    std::cout << " Total Logs Stored  : " << logs.size() << "\n";
    std::cout << "========================================\n";
}