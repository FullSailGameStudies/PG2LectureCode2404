#pragma once
#include "Weapon.h"
class Knife :  public Weapon
{
public:

	Knife(bool serrated_, bool doubleEdged_, int range, int damage)
		: Weapon(range, damage), serrated_(serrated_), doubleEdged_(doubleEdged_)
	{
	}

	void showMe() override;

private:
	bool serrated_;
	bool doubleEdged_;
};

