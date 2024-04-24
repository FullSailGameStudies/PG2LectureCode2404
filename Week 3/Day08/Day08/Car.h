#pragma once
#include <string>
#include <iostream>

class Car
{
public:
	//Car() : mMake("Ford"), mModel("A"), mModelYear(1908), mFuelLevel(0), mMaxFuelLevel(15)
	//{   }

	Car(int year, std::string make, std::string model)
		: mModelYear(year), mMake(make), mModel(model), mFuelLevel(0), mMaxFuelLevel(15)
	{
		std::cout << "Car CTOR\n";
		numberOfCarsMade_++;
	}

	//non-static methods can access non-static AND static members
	virtual std::string vehicleInformation() const;

	void refuel()
	{
		mFuelLevel = mMaxFuelLevel;
	}

	//getter (accessor)
	int modelYear() const
	{
		return mModelYear;
	}

	//setter (mutator)
	void modelYear(int newModelYear)
	{
		if (newModelYear > 1908 && newModelYear < 2100)
		{
			mModelYear = newModelYear;
		}
	}

	static int numberOfCarsMade_;//static (SHARED across all instances)

	//there is NO "this" parameter in static methods
	//therefore, it cannot access NON-static members
	//it can ONLY access static members
	static void Report()
	{
		//std::cout << mModelYear;
		std::cout << "Number of cars made: " << numberOfCarsMade_ << "\n";
	}
protected:
	int mModelYear;//non-static
	std::string mModel;
	std::string mMake;


private:
	int mFuelLevel;
	int mMaxFuelLevel;
};


