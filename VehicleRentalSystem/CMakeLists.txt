cmake_minimum_required(VERSION 3.15)
project(VehicleRentalSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(VehicleRentalSystem CommonDepen.h model/VehicleRental.cpp model/VehicleBranch.cpp constant/VehicleRentalConstants.cpp model/Vehicle.cpp enums/VehicleStatus.cpp model/VehiclePricing.cpp model/VehicleReservation.cpp repo/VehicleRepo.cpp main.cpp )