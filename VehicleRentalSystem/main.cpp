#include <iostream>
#include<map>
#include "service/VehicleBooking.cpp"
using namespace std;

int main() {

    VehicleBooking* vehicleBooking = new VehicleBooking();
    map<string , int> inv = {{"SUV" , 1} , {"Sedan" , 0} , {"bike" , 3}};
    map<string , double> price = {{"SUV" ,12} , {"Sedan" , 80} , {"bike" , 20 }};
    vehicleBooking->addBranch("Koramangala" , inv , price );

    inv = {{"Hatchback" , 4} , {"Sedan" , 3} , {"bike" , 3}};
    price = {{"Hatchback" ,8} , {"Sedan" , 11} , {"bike" , 30 }};
    vehicleBooking->addBranch("JayaNagar" , inv , price );

    inv = {{"SUV" , 4} , {"Sedan" , 4} , {"Hatchback" , 3}};
    price = {{"SUV" ,11} , {"Sedan" , 10} , {"Hatchback" , 20 }};
    vehicleBooking->addBranch("Malleshwaram" , inv , price );


    vehicleBooking->bookVehicle("5 Seat" , "Koramangala" , 2122020  , 10 , 12);
    vehicleBooking->addVehicle("Koramangala" ,"Sedan" , 2 );
    vehicleBooking->bookVehicle("5 Seat" , "Koramangala" , 2122020  , 10 , 12);
    vehicleBooking->bookVehicle("5 Seat" , "Koramangala" , 2122020  , 10 , 12);

    vehicleBooking->bookVehicle("5 Seat" , "Malleshwaram" , 2022020  , 10 , 12);
    vehicleBooking->bookVehicle("5 Seat" , "Malleshwaram" , 2022020  , 10 , 12);
    vehicleBooking->bookVehicle("5 Seat" , "Malleshwaram" , 2022020  , 10 , 12);
    vehicleBooking->bookVehicle("5 Seat" , "Malleshwaram" , 2022020  , 10 , 12);
    vehicleBooking->bookVehicle("5 Seat" , "Malleshwaram" , 2022020  , 10 , 12);
    vehicleBooking->bookVehicle("5 Seat" , "Malleshwaram" , 2022020  , 10 , 12);
    vehicleBooking->bookVehicle("5 Seat" , "Malleshwaram" , 2022020  , 10 , 12);
    vehicleBooking->bookVehicle("5 Seat" , "Malleshwaram" , 2022020  , 10 , 12);
    vehicleBooking->bookVehicle("5 Seat" , "Malleshwaram" , 2022020  , 10 , 12);
    vehicleBooking->bookVehicle("5 Seat" , "Malleshwaram" , 2122020  , 10 , 12);
}
