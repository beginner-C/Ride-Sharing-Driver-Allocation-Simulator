#ifndef IN_TRANSIT_TELEMATICS_H
#define IN_TRANSIT_TELEMATICS_H

#include <string>
#include <vector>

// Represents a 2D GPS coordinate
struct GPSCoordinate {
    double latitude;
    double longitude;
};

// Represents the current state of the ride
enum class TripStatus {
    NOT_STARTED,
    IN_PROGRESS,
    PAUSED,
    COMPLETED,
    EMERGENCY_STOP
};

// Stores a single snapshot of telemetry data
struct TelemetryLog {
    double timestampSec;
    GPSCoordinate location;
    double speedKmh;
    std::string alertMessage;
};

class InTransitTelematics {
private:
    std::string tripID;
    std::string driverID;
    std::string passengerID;

    GPSCoordinate startLocation;
    GPSCoordinate currentLocation;
    GPSCoordinate destination;

    TripStatus status;
    double currentSpeedKmh;
    double maxSpeedKmh;
    double speedLimitKmh;
    double totalDistanceTraveledKm;
    double totalDurationSec;

    int speedingWarnings;
    int harshBrakingEvents;
    bool sosTriggered;

    std::vector<TelemetryLog> logs;

    // Helper function to calculate distance between two coordinates (in km)
    double calculateDistanceKm(const GPSCoordinate& p1, const GPSCoordinate& p2) const;

public:
    // Constructor
    InTransitTelematics(const std::string& tripID,
                        const std::string& driverID,
                        const std::string& passengerID,
                        GPSCoordinate start,
                        GPSCoordinate dest,
                        double speedLimit = 80.0);

    // Core Trip Lifecycle Methods
    void startTrip();
    void pauseTrip();
    void resumeTrip();
    void endTrip();
    void triggerSOS();

    // Real-time Telemetry Update
    void updateTelemetry(GPSCoordinate newLocation, double newSpeedKmh, double elapsedSec);

    // Calculations & Status Queries
    double getRemainingDistanceKm() const;
    double getEstimatedTimeOfArrivalMin() const;
    double getAverageSpeedKmh() const;
    std::string getStatusString() const;

    // Getters (useful for integrating with Payout & Rating modules)
    std::string getTripID() const;
    double getTotalDistanceTraveledKm() const;
    double getTotalDurationSec() const;
    int getSpeedingWarnings() const;
    int getHarshBrakingEvents() const;
    bool isSOSTriggered() const;

    // Reporting
    void displayLiveDashboard() const;
    void displayTripSummary() const;
};

#endif // IN_TRANSIT_TELEMATICS_H