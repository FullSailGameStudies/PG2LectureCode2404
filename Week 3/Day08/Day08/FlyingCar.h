#pragma once
#include "Car.h"

class FlyingCar : public Car
{
public:
	//FlyingCar() : //member initialization list
	//	Car()
	//{
	//}
	FlyingCar(int year, std::string make, std::string model, float maxAltitude) :
		Car(year,make,model)
		,maxAlt_(maxAltitude)
	{
		//DO NOT duplicate what the base does
		//mModelYear = year;
		//mMake = make;
		//mModel = model;

		std::cout << "\tFlying CTOR\n";
		//derived ctor code happens 2nd

		std::cout << mModelYear << "\n";
		//std::cout << mFuelLevel << "\n";//cannot access private members of the base
	}

	std::string vehicleInformation() const override;
private:
	float maxAlt_;

public:
};

