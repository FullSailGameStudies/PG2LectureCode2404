#include "MinecraftPlayer.h"
#include <iostream>

MinecraftPlayer::MinecraftPlayer()
{
	gamerTag_ = "BruceW";
	health_ = 20;
}

MinecraftPlayer::MinecraftPlayer(std::string gamerTag, float health) :
	//member initialization list
	gamerTag_(gamerTag),
	health_(health)
{
}

//HIDDEN parameter called this
void MinecraftPlayer::HUD()// MinecraftPlayer* this)//definition
{
	//   ->   pointer notation
	//  this  pointer to the current object

	//ONLY use this-> to eliminate ambiguity
	std::cout << gamerTag_ << "\nHealth: " << health_;
}
