#include "../CommonDepen.h"
#include "../repo/VehicleRepo.cpp"
#include "../model/VehicleRental.cpp"

VehicleRepo* VehicleRepo::pInstance2 = 0;
VehicleRental* VehicleRental::pInstance = 0;


class VehicleBooking{
public:
    void bookVehicle(string name, string branchName , long long date, int start , int end){
        vector<string> vehicleNames = VehicleRepo::getInstance()->getListOfVehicles(name);
        VehicleBranch* branch = VehicleRental::getInstance()->getBranch(branchName);
        if( branch == NULL)
        {
            cout<<"Branch Not existing"<<endl;
            return;
        }
        if(branch->bookVehicle(date , start , end , vehicleNames))
        {
            cout<<"Booking successful"<<endl;
        } else{
            cout<<" Can't book"<<endl;
        }
    }

    void addBranch(string name , map<string , int> inventory , map<string , double> price){
        VehicleRental::getInstance()->addBranch(name,inventory , price);
    }

    void addVehicle(string name , string vehicleName, int count){
        VehicleRental::getInstance()->addVehicle(name , vehicleName , count);
    }
};

