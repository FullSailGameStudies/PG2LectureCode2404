#include "MinecraftPlayer.h"
#include <iostream>

void MinecraftPlayer::ShowHUD() const
{
	int health = health_;
	health = 0;
	//health_ = 0;
	std::cout << "Health: " << health_ << "\tArmor: " << armor_ << "\tFood: " << food_;
}
