#include "Player.h"
#include <sstream>

Player::Player(std::string csvData, char delimiter)
{
	Deserialize(csvData, delimiter);
}

void Player::Serialize(std::ostream& outFile, char delimiter)
{
	outFile << GamerTag() << delimiter
		<< Food() << delimiter
		<< Health() << delimiter
		<< Armor();
}

void Player::Deserialize(std::string csvData, char delimiter)
{
	std::stringstream playerStream(csvData);
	std::string data;
	std::getline(playerStream, gamerTag_, delimiter);

	std::getline(playerStream, data, delimiter);
	food_ = std::stoi(data);

	std::getline(playerStream, data, delimiter);
	health_ = std::stoi(data);

	std::getline(playerStream, data, delimiter);
	armor_ = std::stoi(data);
}

Player Player::Deserialize(char delimiter, std::string csvData)
{
	std::stringstream playerStream(csvData);
	std::string data;
	std::string gamerTag;
	std::getline(playerStream, gamerTag, delimiter);

	std::getline(playerStream, data, delimiter);
	int food = std::stoi(data);

	std::getline(playerStream, data, delimiter);
	int health = std::stoi(data);

	std::getline(playerStream, data, delimiter);
	int armor = std::stoi(data);
	return Player(gamerTag, armor, food, health);
}
