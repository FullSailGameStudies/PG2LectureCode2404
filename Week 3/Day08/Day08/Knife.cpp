#include "Knife.h"
#include <iostream>

void Knife::showMe()
{
	std::string serrated = (serrated_) ? "serrated " : "";
	std::string edged = (doubleEdged_) ? "double-edge " : "";
	std::cout << "I am a " << edged << serrated << "knife. ";
	Weapon::showMe();//EXTENDING the base by calling the base method
}
