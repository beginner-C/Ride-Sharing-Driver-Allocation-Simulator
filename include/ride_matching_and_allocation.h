#ifndef RIDEMATCHING_H
#define RIDEMATCHING_H

#include <iostream>
#include <string>
using namespace std;

class Driver {
private:
     int driverID;
     string driverName;
     string vechileType;
     bool availability;

public:
 Driver ();
 Driver (int id, string name, string vehicle);

 void displayDriver()  const;
 bool isAvailable() const;
 void setAvailability(bool status);
};


class Ride {
    private:
    int rideID;
    string pickupLocation;
    string dropLocation;
    string rideStatus;

public:
Ride();
Ride (int id, string pickup, string drop);

void displayRide() const;
void setRideStatus (string status);
};
class RideMatching {
private:
  int allocationID;

  public:
  RideMatching();
  RideMatching(int id);

  void matchDriver(Driver &driver, Ride &ride);
   void displayAllocationID() const;
};

#endif