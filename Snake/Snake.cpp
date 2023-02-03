#include "Snake.h"
#include "ConsoleWriter.h"
#include "Console.h"
using utility::ConsoleWriter;
using utility::Console;
using std::vector;

//All methods by Ximena

Snake::Snake()
	:direction(Right), body(createBodyVector())
{ }

std::vector<COORD> Snake::getBody()
{
	return body;
}

int Snake::getDirection()
{
	return direction;
}

int Snake::getSnakeLength()
{
	return body.size();
}

void Snake::setDirection(int direction)
{
	if (isDirectionHorizontal(this->direction) != isDirectionHorizontal(direction))
	{
		this->direction = direction;
	}	
}

void Snake::move()
{
	COORD head = getNextHeadPosition();

	body.push_back(head);
	body.erase(body.begin());
}

COORD Snake::getHead()
{
	return body.back();
}

COORD Snake::getNextHeadPosition()
{
	COORD head = getHead();
	if (isDirectionHorizontal(direction)) {
		if (direction == Left)
			head.X--;
		else
			head.X++;
	}
	else
	{
		if (direction == Up)
			head.Y--;
		else
			head.Y++;
	}
	return head;
}

bool Snake::isInBody(COORD coordinate)
{
	for (int i = 0; i < body.size(); i++)
	{
		if (body.at(i).X == coordinate.X && body.at(i).X == coordinate.X)
			return true;
	}
	return false;
}

void Snake::increaseSnakeLength()
{
	body.insert(body.begin(), { body.front().X, body.front().Y });
}

bool Snake::isDirectionHorizontal(int direction)
{
	switch (direction)
	{
	case Left:
	case Right:
		return true;

	default:
		return false;
	}
}

std::vector<COORD> Snake::createBodyVector()
{
	std::vector<COORD> body;
	for (int i = 0; i < 10; i++)
		body.push_back({ (SHORT)(58 + i), (SHORT)25 });
	return body;
}

void Snake::resetSnakeBody()
{
	std::vector<COORD> body;
	for (int i = 0; i < 10; i++)
		body.push_back({ (SHORT)(58 + i), (SHORT)25 });
	this->body = body;
}

