#include "../CommonDepen.h"
#include<map>
#include<vector>
#include "VehicleReservation.cpp"
#include "VehiclePricing.cpp"

class VehicleBranch{
    int id;
    string name;
    map<string , int> inventory;
    VehiclePricing pricing;
    map<long long , list<VehicleReservation*>> branchBookingRepo;

public:
    VehicleBranch(string branchName , map<string , int> inv , map<string , double> p){
        pricing = VehiclePricing(p);
        inventory = inv;
        name = branchName;
    }

    void addVehicle(string name , int count){
        inventory[name] +=count;
    }

    bool bookVehicle(long long date , int start , int end , vector<string> names){
        bool canBook = false;
        string vechicleName = "";
        for( auto itr : names){
           if(isVehicleAvailable(itr , start , end , date)) {
               canBook = true;
               vechicleName = itr;
               break;
           }
        }

        if(canBook){
            Vehicle vehicle = Vehicle(vechicleName);
            VehicleReservation* temp = new VehicleReservation(id,vehicle , start , end );
            branchBookingRepo[date].push_back(temp);
            cout<<" price is:"<< pricing.getRate(vechicleName) * (end - start)<<" ";
        }
        return canBook;
    }

    bool isVehicleAvailable(string vechname , int start , int end , long long date){
            auto temp = branchBookingRepo[date];
            int maxCount = inventory[vechname];
            if( maxCount == 0)
                return false;
            int count = 0;
            if( temp.empty()){
                return true;
            } else{
                for( auto itr : temp){
                    if( (itr->getVehicleObj().getName() == vechname) &&
                                (itr->getStartTime() <= start ||
                        itr->getEndTime() >= end)){
                        count++;
                    }
                }
            }
            if( count < maxCount)
                return true;
            else
                return false;
    }

    const string &getName() const {
        return name;
    }
};