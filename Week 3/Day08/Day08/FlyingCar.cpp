#include "FlyingCar.h"

std::string FlyingCar::vehicleInformation() const
{
    return Car::vehicleInformation() + "Max Altitude:" + std::to_string(maxAlt_);
}
