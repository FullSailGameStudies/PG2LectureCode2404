#pragma once
#include <string>
#include <fstream>
class Player
{
public:

	Player(const std::string& tag, float armor, float food, float health)
		: gamerTag_(tag), armor_(armor), food_(food), health_(health)
	{
	}

	//Option 1: a constructor that calls Deserialize
	Player(std::string csvData, char delimiter);

	std::string GamerTag() const { return gamerTag_; }
	float Armor() const { return armor_; }
	float Food() const { return food_; }
	float Health() const { return health_; }

	void Serialize(std::ostream& outFile, char delimiter);//where and how)
	void Deserialize(std::string csvData, char delimiter);

	//Option 2: Deserialize creates the object
	static Player Deserialize(char delimiter, std::string csvData);

private:
	std::string gamerTag_;
	float armor_, food_, health_;
};

