#include "Pistol.h"
#include <iostream>

void Pistol::showMe()
{
	Weapon::showMe();//EXTENDING the base by calling the base method
	std::cout << "Rounds: " << rounds_ << "\tMagazine Capacity: " << magCapacity_ << "\n";
}
