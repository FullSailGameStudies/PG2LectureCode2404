#include "Calculator.h"

//method DEFINITION (the code for the method)
int Calculator::minus(int number1, int number2)
{
	return number1 - number2;
}

double Calculator::mult(double num, double factor)
{
	return num * factor;
}

bool Calculator::isEven(int aNumber)
{
	return !(aNumber % 2);
}