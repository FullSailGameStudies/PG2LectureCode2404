#include <iostream>
#include "Weapon.h"

Weapon::Weapon(int range, int damage) : mRange(range), mDamage(damage)
{
}

void Weapon::showMe()
{
	std::cout << "I have a range of " << mRange << " and can do a maximum of " << mDamage << " damage. \n";
}

int Weapon::calcDamage()
{
	return rand() % (mDamage+1);
}

int Weapon::calcDamage(int modifier)
{
	return rand() % (mDamage + modifier + 1);
}
