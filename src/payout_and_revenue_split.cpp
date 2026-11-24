#include "../include/payout_and_revenue_split.h"
#include <iostream>
using namespace std;
 
RevenueSplit::RevenueSplit() {
    totalFare = 0;
    commissionPercent = 20;
    tollAmount = 0;
    platformShare = 0;
    driverShare = 0;
}
RevenueSplit::RevenueSplit(double fare, double commission, double toll) {
    totalFare = fare;
    commissionPercent = commission;
    tollAmount = toll;
    platformShare = 0;
    driverShare = 0;
}
RevenueSplit::~RevenueSplit() {
}
 
void RevenueSplit::setData(double fare, double commission, double toll) {
    totalFare = fare;
    commissionPercent = commission;
    tollAmount = toll;
}
 
void RevenueSplit::getData() {
    cout << "Fare: " << totalFare << endl;
    cout << "Commission: " << commissionPercent << "%" << endl;
    cout << "Toll: " << tollAmount << endl;
}
double RevenueSplit::getDriverShare() {
    return driverShare;
}
void RevenueSplit::calculateSplit() {
    platformShare = (totalFare * commissionPercent) / 100;
    driverShare = totalFare - platformShare + tollAmount;
}
void RevenueSplit::displaySplit() {
    cout << "  Revenue Split: " << endl;
    cout << "Total Fare: Rs. " << totalFare << endl;
    cout << "Commission (" << commissionPercent << "%): Rs. " << platformShare << endl;
    cout << "Toll Added: Rs. " << tollAmount << endl;
    cout << "Driver Earning: Rs. " << driverShare << endl;
    cout << "Platform Earning: Rs. " << platformShare << endl;
}
 
Payout::Payout() {
    driverId = 0;
    driverName = "Unknown";
    payoutAmount = 0;
    payoutStatus = "Pending";
}
Payout::Payout(int id, string name, double amount) {
    driverId = id;
    driverName = name;
    payoutAmount = amount;
    payoutStatus = "Pending";
}
Payout::~Payout() {
}
 
void Payout::setData(int id, string name, double amount, string status) {
    driverId = id;
    driverName = name;
    payoutAmount = amount;
    payoutStatus = status;
}
 
void Payout::getData() {
    cout << "Driver ID: " << driverId << endl;
    cout << "Driver Name: " << driverName << endl;
    cout << "Payout Amount: " << payoutAmount << endl;
    cout << "Status: " << payoutStatus << endl;
}
void Payout::processPayout() {
    if (payoutAmount > 0) {
        payoutStatus = "Paid";
    } else {
        payoutStatus = "Failed";
    }
}
void Payout::displayPayout() {
    cout << "  Payout Details: " << endl;
    cout << "Driver ID: " << driverId << endl;
    cout << "Driver Name: " << driverName << endl;
    cout << "Payout Amount: Rs. " << payoutAmount << endl;
    cout << "Status: " << payoutStatus << endl;
}