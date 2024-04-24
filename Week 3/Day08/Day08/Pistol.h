#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:

	Pistol(int rounds, int magCapacity, int range, int damage)
		: Weapon(range,damage), rounds_(rounds), magCapacity_(magCapacity)
	{
	}

	int Rounds() const { return rounds_; }
	int MagCapacity() const { return magCapacity_; }

	void Rounds(int rounds) { rounds_ = rounds; }
	void MagCapacity(int magCap) { magCapacity_ = magCap; }

	Pistol operator+(Pistol const& otherPistol)
	{
		Pistol newPistol(
			otherPistol.rounds_ + rounds_, 
			otherPistol.magCapacity_, 
			range(), 
			damage());
		return newPistol;
	}

	void showMe() override;

private:
	int rounds_, magCapacity_;
};

