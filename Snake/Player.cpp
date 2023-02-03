#include "Player.h"
#include "Console.h"
using utility::ConsoleWriter;
using utility::Console;
using std::string;

//All methods by Sharmaine

Player::Player()
	: playerName(" "), playerScore()
{
}

void Player::increasePlayerScore()
{
	playerScore++;
}

std::string Player::getPlayerName()
{
	return playerName;
}

int Player::getPlayerScore()
{
	return playerScore;
}

void Player::setPlayerName(std::string name)
{
	this->playerName = name;
}

void Player::setPlayerScore(int score)
{
	this->playerScore = score;
}
