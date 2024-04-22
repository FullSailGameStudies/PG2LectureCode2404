#pragma once
#include <string>

//class declaration
//	what can the class DO (methods)
//	what describes the class (fields/data)
class MinecraftPlayer
{
	//default access is PRIVATE

public:
	//ctors (constructors)
	MinecraftPlayer();//default constructor
	MinecraftPlayer(std::string gamerTag, float health);

	void HUD();//declaration

	//getters (accessor)
	//	DO NOT CHANGE fields
	std::string GetGamerTag() const { return gamerTag_; }
	float Health() const { return health_; }

	//setters (mutators)
	//	CHANGE fields
	//	DO NOT return data
	void SetGamerTag(const std::string& gamerTag) { 
		if (gamerTag.size() > 0 && gamerTag != "Steve") // CheckForInnappropriate()
		{
			gamerTag_ = gamerTag;
		}
	}
	void Health(float health) {
		if (health >= 0 && health <= 20)
			health_ = health;
	}


public://anything after this is public UNTIL the next access modifier

private:
	std::string gamerTag_;
	float health_;

private:
};

