﻿// Day08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Inheritance.h"
#include "Polymorphism.h"
#include "Car.h"
#include "FlyingCar.h"
#include <vector>
#include "Pistol.h"
#include "Knife.h"


void DoIt()
{
	static int num = 0;
	std::cout << num << "\n";
	num++;
}

int main()
{
	for (size_t i = 0; i < 10; i++)
	{
		DoIt();
	}
	Car myRide(1988, "Ford", "Mustang GT5.0");
	FlyingCar jetsonMobile(2025, "Tesla", "X-Wing", 60);
	jetsonMobile.vehicleInformation();

	Car::Report();

	Account savings1(500);
	Account savings2(100);
	Account Savings3 = savings1 + 5;

	std::vector<int> n1{ 1,2,3 }, n2{ 4,5,6 };
	//std::vector<int> n3 = n1 + n2;
	/*
        ╔═══════════════╗
        ║  Inheritance  ║
        ╚═══════════════╝

								╔═════════╗     ╔══════════╗
				         class  ║SomeClass║  :  ║OtherClass║
								╚═════════╝     ╚══════════╝
									 │                │
									 └──┐             └──┐
								   ┌────▼────┐      ┌────▼────┐
								   │ Derived │      │  Base   │
								   │  Class  │      │  Class  │
								   └─────────┘      └─────────┘

			Access modes:
				public inheritance:
				protected inheritance:
				private inheritance: (default if not specified)
	


				CONSTRUCTORS: the derived constructor must call a base constructor
				public SomeClass(.....) : baseClass(....)


			Lecture Code: add a FlyingCar class that derives from Car
             
    */








	/*
        ╔═════════════════════════════╗
        ║  COMPILE-TIME Polymorphism  ║
        ╚═════════════════════════════╝

		Method Overloading:
			- changing the number of parameters
			- changing the types of the parameters

		Lecture Code: Overload the refuel method in Car

	*/







	/*
        ╔═════════════════════════════╗
        ║  COMPILE-TIME Polymorphism  ║
        ╚═════════════════════════════╝

		Operator Overloading

		Lecture Code: overload the + operator in Account

	*/









	/*
        ╔════════════════════════╗
        ║  RUNTIME Polymorphism  ║
        ╚════════════════════════╝

		╔═════════════╗
		║ OVERRIDING  ║ - changing the behavior of a base method
		╚═════════════╝

		1) add 'virtual' to the base method
		2) add a method to the derived class that has the same signature as the base.
			OPTIONALLY put 'override' on the derived method


		FULLY OVERRIDING:
			not calling the base method from the derived method

		EXTENDING:
			calling the base method from the derived method
			to call the base method...  baseClassName::method(...)



		Lecture Code: override the print method in the base/derived classes in the Polymorphism.h file

	*/



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			add a new class, Pistol, that derives from Weapon.
			Pistol should have fields with getters/setters for rounds and magCapacity.
			Add a constructor that calls the base constructor


			Add an OVERLOAD of the calcDamage method in the Weapon class.
			The overload should take an int parameter called modifier
			to increase the damage when calculating the damage.


			overload the + in the Pistol class to add 2 pistols
				- it sets the magCapacity to the max of the 2 pistols
				- adds the # of rounds from both pistols. should not exceed the magCapacity.
	

			Override Weapon's showMe method in the Pistol class.
			In Pistol's version, call the base version then print out the rounds and magCapacity



	*/
	Pistol banger(10, 15, 200, 50);//lives on the stack
	Knife stabby(true, true, 3, 10);
	//Weapon wpn(100, 200);
	Pistol* pPistol = new Pistol(10, 15, 200, 50);//lives on the HEAP
	(*pPistol).showMe();
	pPistol->showMe();
	//what is being "COPIED"? the memory address is being copied. NOT the object
	Weapon* wpn2 = pPistol;//UPCASTING
	std::cout << "\n" << wpn2 << "\n" << pPistol << "\n";

	std::vector<Weapon*> inventory;
	std::vector<std::unique_ptr<Weapon>> backpack;
	backpack.push_back(std::make_unique<Knife>(true, true, 3, 10));
	backpack.push_back(std::make_unique<Pistol>(10, 15, 200, 50));
	std::cout << "\n\nDora's Backpack\n";
	for (auto& wpn : backpack)
	{
		wpn->showMe();//runtime polymorphism
	}


	//??? Knife is-a Weapon
	Weapon wpn1 = stabby;//performs a COPY

	{
		std::unique_ptr<Pistol> pGun = std::make_unique<Pistol>(10, 15, 200, 50);
		//pGun->showMe();
		std::unique_ptr<Weapon> baseWpn = std::move(pGun);
		//pGun->showMe();
	}//pGun goes out of scope and the Heap memory is deleted

	int aNum = 5;
	float fNum = aNum;//IMPLICIT cast
	aNum = (int)n1.size();//EXPLICIT cast
	aNum = std::stoi("5");


	//int fave = 5;
	//int* pNum = &fave;//pointer to the stack
	//pNum = new int(10);//allocate the int on the HEAP
	//int* otherPointer = pNum;
	//delete otherPointer;
	//std::cout << fave << "\n" << (*pNum) << "\n";
	//delete pNum;//delete anything that you have "newed" = new
	//std::cout << fave << "\n" << (*pNum) << "\n";




	//-----------------------------------------------
	//  save for day 9
	/*
		╔════════════╗
		║ Unique_ptr ║
		╚════════════╝

		Using unique pointers w/ overridden methods


        ╔═══════════╗ 
        ║ UPCASTING ║ - casting a derived type variable to a base type variable
        ╚═══════════╝ 

        This is ALWAYS safe.

	
		To maintain the original object, we need a pointer though. If not, then we're just calling the copy constructor of the base class and lose all the info of the derived.

		Unique pointers owns and manages an object through a pointer.
		std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 5);

		
		You can upcast by using the base type in the unique_ptr.
		std::unique_ptr<base> pBase = std::make_unique<derived>("Gotham", 5);
		  OR
		std::unique_ptr<base> pBase = std::move(pDerived); https://learn.microsoft.com/en-us/cpp/standard-library/utility-functions?view=msvc-170&redirectedfrom=MSDN&f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(std%253A%253Amove)%3Bk(move)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue#move



		Lecture Code: 
			use make_unique and unique_ptr to create a derived instance
			use std::move to upcast it to a base
	*/
	derived der1("Gotham", 1);
	base base1 = der1; //calls the assignment operator of base therefore you lose all the derived parts. base1 is JUST a base object.
	der1.print();
	std::cout << "\n";
	base1.print();



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

		Create a vector that holds unique pointers of Weapon.
		Create instances of Weapon and Pistol using make_unique.
		Add them to the vector.

		Loop over the vector and call showMe on each weapon.

	*/
}

