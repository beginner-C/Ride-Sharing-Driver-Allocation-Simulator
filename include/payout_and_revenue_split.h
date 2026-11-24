 #ifndef MEMBER5_PAYOUT_H
#define MEMBER5_PAYOUT_H

#include <string>
using namespace std;

class RevenueSplit {
private:
    double totalFare;
    double commissionPercent;
    double tollAmount;
    double platformShare;
    double driverShare;
public:
    RevenueSplit();
    RevenueSplit(double fare, double commission, double toll);
    ~RevenueSplit();
    void setData(double fare, double commission, double toll);
    void getData();
    double getDriverShare();
    void calculateSplit();
    void displaySplit();
};

class Payout {
private:
    int driverId;
    string driverName;
    double payoutAmount;
    string payoutStatus;
public:
    Payout();
    Payout(int id, string name, double amount);
    ~Payout();
    void setData(int id, string name, double amount, string status);
    void getData();
    void processPayout();
    void displayPayout();
};

#endif