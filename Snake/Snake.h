#include "ConsoleReader.h"
#include "ConsoleWriter.h"
#include <string>
#include <vector>
//All methods by Ximena
class Snake
{
private:
	static const unsigned char SnakeChar = 254;
	
	std::vector<COORD> body;
	int direction;


public:
	static const unsigned int Up = 1;
	static const unsigned int Down = 2;
	static const unsigned int Right = 3;
	static const unsigned int Left = 4;
	
	//Constructor
	Snake();

	//Getter methods
	std::vector<COORD> getBody();
	int getDirection();
	int getSnakeLength();
	
	//Set Methods
	void setDirection(int direction);
	
	//Moving Methods
	void move();

	//Other Methods
	bool isInBody(COORD coordinate);
	void increaseSnakeLength();

	void resetSnakeBody();

private:
	COORD getHead();
	COORD getNextHeadPosition();


	static bool isDirectionHorizontal(int direction);
	static std::vector<COORD> createBodyVector();
};