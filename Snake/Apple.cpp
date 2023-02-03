#include "Apple.h"
#include "Random.h"
using utility::Random;
using utility::Coordinate;

//All methods by Sharmaine

Apple::Apple()
	: appleCoord(initializeApple())

{ }

COORD Apple::initializeApple()
{
	SHORT appleXPosition = Random::getRandomInteger(16, 109);
	SHORT appleYPosition = Random::getRandomInteger(9, 39);
	return { appleXPosition, appleYPosition };
}

COORD Apple::getAppleCoord()
{
	return appleCoord;
}

//Generate random location of apple using random num generator
void Apple::randomlySetAppleCoord()
{
	SHORT appleXPosition = Random::getRandomInteger(16, 109);
	SHORT appleYPosition = Random::getRandomInteger(9, 39);
	appleCoord = { appleXPosition, appleYPosition };
}
