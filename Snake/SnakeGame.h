#pragma once
#include "ConsoleReader.h"
#include "ConsoleWriter.h"
#include "Snake.h"
#include "Apple.h"
#include "Player.h"
#include <string>
#include <vector>



class SnakeGame
{
private:
	//Chars
	static const unsigned char Speed = 250;
	static const unsigned char SnakeChar = 79;
	static const unsigned char SpaceChar = 32;
	static const unsigned char AppleChar = 162;

	//Coordinates for Map
	static const COORD topLeftMap;
	static const COORD bottomRightMap;
	static const COORD topLeftScoreboard;
	static const COORD bottomRightScoreboard;
	static const COORD middleOfScreen;
	static const COORD underMiddleOfScreen;
	static const COORD mapRegionTopLeft;
	static const COORD mapRegionBottomRight;


	utility::ConsoleWriter writer;
	utility::ConsoleReader reader;

	Snake snake;
	Apple apple;
	Player player;
	bool playing;

public:
	//Ximena & Sharmaine
	SnakeGame();
	//Ximena
	void start();


private:

	//View Methods
	//Ximena
	void updateInput();
	//Ximena
	void updateView();
	//Sharmaine
	void displayMap();
	//Sharmaine
	void displayScoreboard();
	//Ximena
	void displaySnake();
	//Sharmaine (method)
	//Ximena (validation)
	void displayApple();
	//Ximena
	void clearSnakeRegion();
	//Ximena
	void update();

	//Game Methods
	//Sharmaine
	void playOneRound();
	//Sharmaine
	bool ateApple();
	//Sharmaine
	bool hitWall();
	//Sharmaine
	bool hitSelf();
	//Sharmaine
	void loseGame();
	//Sharmaine
	void playAgain();

};
