#include "surge_pricing_and_distance_matrix.h"
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    float dist;
    cout<<"Write distance for the ride: "<<endl;
    cin>>dist;
    priceCalculator CalculatingRideFare(dist);
    CalculatingRideFare.inputtraffic();
    CalculatingRideFare.display();
    return 0;

}