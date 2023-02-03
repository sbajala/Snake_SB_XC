#pragma once
#include "ConsoleWriter.h"
#include "Coordinate.h"

//All methods by Sharmaine

class Apple
{
private:
	
	utility::ConsoleWriter writer;
	COORD appleCoord;

	static COORD initializeApple();

public:
	Apple();

	COORD getAppleCoord();
	void randomlySetAppleCoord();
};

