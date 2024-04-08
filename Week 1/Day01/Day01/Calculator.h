#pragma once
class Calculator
{
public:
	//the DECLARATION of the sum method
	int minus(int number1, int number2);

	static double mult(double num, double factor);


	/// <summary>
	/// Tells you if a number is even or not
	/// </summary>
	/// <param name="aNumber">The number to check</param>
	/// <returns>true or false</returns>
	bool isEven(int aNumber);
};

