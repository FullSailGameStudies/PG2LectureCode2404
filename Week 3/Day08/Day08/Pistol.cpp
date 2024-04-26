#include "Pistol.h"
#include <iostream>

void Pistol::showMe()
{
	std::cout << "I am a pistol with " << rounds_ << " rounds and a can hold up to" << magCapacity_ << " rounds. ";
	Weapon::showMe();//EXTENDING the base by calling the base method
}
