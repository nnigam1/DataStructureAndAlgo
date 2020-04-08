#include "../CommonDepen.h"
#include "Vehicle.cpp"
#include "../constant/VehicleRentalConstants.cpp"
#include "../enums/VehicleStatus.cpp"


class VehicleReservation{
    int id;
    int branchId;
    Vehicle vehicleObj;
    int startTime;
    int endTime;
public:
    VehicleReservation(int branchId, const Vehicle& vehicleObj, int startTime, int endTime) : branchId(branchId),
                                                                                              vehicleObj(vehicleObj),
                                                                                              startTime(startTime),
                                                                                              endTime(endTime) {}

    int getId() const {
        return id;
    }

    int getBranchId() const {
        return branchId;
    }

    Vehicle &getVehicleObj() {
        return vehicleObj;
    }

    int getStartTime() const {
        return startTime;
    }

    int getEndTime() const {
        return endTime;
    }
};

