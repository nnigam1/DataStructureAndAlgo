#include "../CommonDepen.h"
#include<map>

class VehiclePricing{
    map<string  , double> vehiclePricing;
public:
    VehiclePricing(){};

    VehiclePricing(map<string , double> temp){
        vehiclePricing = temp;
    }

    void addPricing(double rate , string name){
        vehiclePricing.insert({name , rate});
    }

    double getRate(string name){
        return vehiclePricing[name];
    }
};
