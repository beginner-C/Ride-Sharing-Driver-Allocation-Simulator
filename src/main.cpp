#include "RideMatching.h"

int main() {
   
    Driver driver1(101, "Ali", "Car");
    Ride ride1(201, "UMT Lahore", "Johar Town");
    RideMatching matching1(301);

    cout << "===== RIDE MATCHING SYSTEM =====" << endl;

    matching1.displayAllocationID();
    matching1.matchDriver(driver1, ride1);

    return 0;
}