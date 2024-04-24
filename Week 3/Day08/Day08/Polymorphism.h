#pragma once
#include <iostream>
#include <string>

/*

	COMPILE-TIME Polymorphism

	Method Overloading:
		- changing the number of parameters
		- changing the types of the parameters

*/
class Calculator
{
public:
	int add(int n1, int n2);
	int add(int n1, int n2, int n3);
	float add(float f1, float f2);
	double add(double d1, double d2);
};


/*

	COMPILE-TIME Polymorphism

	Operator Overloading

*/
class Account
{
private:
	double mBalance;

public:
	Account(double balance) : mBalance(balance)
	{	}

	Account operator+(Account const& acct2)
	{
		Account combined(mBalance + acct2.mBalance);
		return combined;
	}
};




/*

	RUNTIME Polymorphism

	method overriding

*/
class base
{
private:
	int mNum;
public:
	base(int num) : mNum(num)
	{

	}
	//STEP 1: mark the BASE method as virtual
	virtual void print()
	{
		std::cout << "Hello base " << mNum << "\n";
	}
};

class derived : public base
{
private:
	std::string mStr;
public:
	derived(std::string str, int num) : base(num), mStr(str)
	{ }
	//STEP 2: provide a method with the same SIGNATURE (header) of the base method
	void print() override
	{
		//a FULL override does NOT call the base method
		//an EXTENDED override will call the base method
		base::print();
		std::cout << "Aquaman is the worst!!\n";
	}
};
