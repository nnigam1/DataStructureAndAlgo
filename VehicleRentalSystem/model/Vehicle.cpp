#include "../CommonDepen.h"

class Vehicle {
    string id;
    string name;

public:
    Vehicle(string name) : name(name) {}

    string getName(){
        return name;
    }
};

class Car : Vehicle{
};

class Sedan : Car{
};

class Bike : Vehicle{
};

