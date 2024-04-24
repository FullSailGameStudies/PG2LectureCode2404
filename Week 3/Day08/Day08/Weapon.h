#pragma once
class Weapon
{
private:
	int mRange;
	int mDamage;

public:
	Weapon(int range, int damage);

	virtual void showMe() = 0;
	int calcDamage();
	int calcDamage(int modifier);

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

