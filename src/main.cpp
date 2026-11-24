#include <iostream>
#include "../include/payout_and_revenue_split.h"
using namespace std;

int main() {
    double fare, commission, toll;
    int id;
    string name;

    cout << "Enter Driver ID: ";
    cin >> id;
    cout << "Enter Driver Name: ";
    cin >> name;
    cout << "Enter Total Fare: ";
    cin >> fare;
    cout << "Enter Commission % : ";
    cin >> commission;
    cout << "Enter Toll Amount: ";
    cin >> toll;

    RevenueSplit r1;
    r1.setData(fare, commission, toll);
    r1.calculateSplit();

    Payout p1;
    p1.setData(id, name, r1.getDriverShare(), "Pending");
    p1.processPayout();

    cout << endl;
    r1.displaySplit();
    p1.displayPayout();

    return 0;
}