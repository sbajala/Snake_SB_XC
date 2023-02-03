#pragma once
#include <string>
#include "ConsoleWriter.h"

//All methods by Sharmaine

class Player
{
private:
	utility::ConsoleWriter writer;
	std::string playerName;
	int playerScore;

public:
	Player();
	
	void increasePlayerScore();
	
	void setPlayerName(std::string name);
	void setPlayerScore(int score);

	int getPlayerScore();
	std::string getPlayerName();
};

