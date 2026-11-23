#include "surge_pricing_and_distance_matrix.h"
#include<iostream>
#include<cmath>
using namespace std;
 priceCalculator::priceCalculator(int tDistance){
    distance =tDistance;
    fare=0;
    traffic=0;
    pricePerKm;
}
   void  priceCalculator::inputtraffic(){
        cout<<"Is there traffic? press 1 for yes and 0 for no: "<<endl;
        cin>>traffic;
   

        if(traffic==1){
            fare =pricePerKm * distance;
            fare+=fare*0.3;
        }
        else{
           fare =pricePerKm * distance;
      
        }
     }
         float priceCalculator::gettraffic(){
            return traffic;
        }
        
     double priceCalculator::getfare(){
        return fare;
     }
   
      void priceCalculator::display(){
        cout<<"Total fare for the ride is: "<<fare<<endl;
      }
     
 