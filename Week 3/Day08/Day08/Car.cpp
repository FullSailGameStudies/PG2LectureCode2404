#include "Car.h"

int Car::numberOfCarsMade_ = 0;
std::string Car::vehicleInformation() const
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}
