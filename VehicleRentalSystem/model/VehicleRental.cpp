#include "../CommonDepen.h"
#include "VehicleBranch.cpp"

class VehicleRental{
    string id;
    string name;
    list<VehicleBranch*> branches;
    static VehicleRental *pInstance;
private:
    VehicleRental(){
    };
public:
    static VehicleRental* getInstance(){
        if( pInstance == NULL )
        {
            pInstance =  new VehicleRental();
        }
        return pInstance;
    }

    void addBranch(string name , map<string , int> inventory , map<string , double> price){
        VehicleBranch* temp = new VehicleBranch(name, inventory , price);
        branches.push_back(temp);
    }

    VehicleBranch* getBranch(string branchName){
        for( auto itr : branches){
            if( itr->getName() == branchName)
                return itr;
        }
        return NULL;
    }

    void addVehicle(string name , string vehicleName, int count){
        auto temp = getBranch(name);
        temp->addVehicle(vehicleName, count);
    }

};


