#include <iostream>
#include "in_transit_telematics.h"

int main() {
    // Example coordinates (Lahore area)
    GPSCoordinate pickup = {31.5204, 74.3587};
    GPSCoordinate dropoff = {31.5820, 74.3294};

    // Initialize the telematics engine for a ride
    InTransitTelematics ride("TRIP-1042", "DRV-205", "PSG-889", pickup, dropoff, 70.0);

    // Start the trip
    ride.startTrip();

    // Simulate GPS & speed updates along the route
    std::cout << "\n--- Update 1: Normal driving ---\n";
    ride.updateTelemetry({31.5350, 74.3500}, 55.0, 120.0);
    ride.displayLiveDashboard();

    std::cout << "\n--- Update 2: Overspeeding ---\n";
    ride.updateTelemetry({31.5550, 74.3420}, 85.0, 100.0);
    ride.displayLiveDashboard();

    std::cout << "\n--- Update 3: Sudden traffic (Harsh Braking) ---\n";
    ride.updateTelemetry({31.5680, 74.3350}, 40.0, 90.0);
    ride.displayLiveDashboard();

    std::cout << "\n--- Update 4: Approaching destination ---\n";
    ride.updateTelemetry({31.5820, 74.3294}, 30.0, 110.0);

    // End the trip
    ride.endTrip();

    // Print final report (can be passed to Payout & Rating modules)
    ride.displayTripSummary();

    return 0;
}