#pragma once
class priceCalculator{
    private:
    int pricePerKm=35;
    int distance;
    double surgedPrice;
    float traffic;
    double fare;
    public:
    priceCalculator(int tDistance);
    double getfare();
    void inputtraffic();
    float gettraffic();
    void display();
};