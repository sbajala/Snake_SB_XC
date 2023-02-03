#include <string>
#include <time.h>
#include "SnakeGame.h"
#include "Console.h"
#include "Random.h"
using utility::ConsoleWriter;
using utility::ConsoleReader;
using utility::Console;
using utility::Random;
using std::string;
using std::to_string;

const COORD SnakeGame::topLeftMap = { 15, 8 };
const COORD SnakeGame::bottomRightMap = { 110, 40 };
const COORD SnakeGame::topLeftScoreboard = { 15, 3 };
const COORD SnakeGame::bottomRightScoreboard = { 110, 7 };
const COORD SnakeGame::middleOfScreen = { 58, 15 };
const COORD SnakeGame::underMiddleOfScreen = { 48, 18 };
const COORD SnakeGame::mapRegionTopLeft = { 16, 9 };
const COORD SnakeGame::mapRegionBottomRight = { 109, 39 };


//Ximena & Sharmaine
SnakeGame::SnakeGame()
	: reader(), writer(), snake(), apple(), player(), playing(true)
{
}

//Ximena
void SnakeGame::start()
{
	writer.clear();
	displayMap();
	displayScoreboard();
	displayApple();
	displaySnake();

	while (playing) {
		update();
		Sleep(Speed);
	}

	writer.clear();
	writer.setCursorPosition({ middleOfScreen });
	writer.write("Bye " + player.getPlayerName());
	writer.writeLine();
	writer.writeLine();
	writer.pause();
}

//Ximena
void SnakeGame::update()
{
	
	updateView();
	updateInput();
	playOneRound();
}

//Ximena
//read user input to update snake direction
void SnakeGame::updateInput()
{
	if (reader.isUpArrowPressed()) {
		snake.setDirection(snake.Up);
	}
	else if (reader.isRightArrowPressed()) {
		snake.setDirection(snake.Right);
	}
	else if (reader.isDownArrowPressed()) {
		snake.setDirection(snake.Down);
	}
	else if (reader.isLeftArrowPressed()) {
		snake.setDirection(snake.Left);
	}
}

//Ximena
void SnakeGame::updateView()
{
	clearSnakeRegion();
	snake.move();
	displaySnake();
}

//Sharmaine
void SnakeGame::displayMap()
{
	
	writer.setCursorPosition(middleOfScreen);
	writer.write("Enter your name: ");
	player.setPlayerName(reader.readWord());
	writer.clear();

	writer.drawRectangle(topLeftMap, bottomRightMap);
	writer.setCursorVisible(false);
}

//Sharmaine
void SnakeGame::displayScoreboard()
{
	writer.drawRectangle(topLeftScoreboard, bottomRightScoreboard);

	writer.setCursorPosition(19, 5);
	writer.write("Player: " + player.getPlayerName());

	writer.setCursorPosition(55, 5);
	writer.write("Score: " + to_string(player.getPlayerScore()));

	writer.setCursorPosition(90, 5);
	writer.write("Snake Length: " + to_string(snake.getBody().size()));
	writer.setCursorVisible(false);
}

//Ximena
void SnakeGame::displaySnake()
{
	std::vector<COORD> body = snake.getBody();
	
	for (int i = 0; i < body.size() ; i++)
	{
		writer.setCursorPosition(body.at(i));
		writer.setCharacterAtPosition(body.at(i), SnakeChar);
	}
	
}

//Sharmaine (method)
//Ximena (validation)
void  SnakeGame::displayApple()
{
	while (snake.isInBody(apple.getAppleCoord()))
		apple.randomlySetAppleCoord();
	writer.setCharacterAtPosition(apple.getAppleCoord(), AppleChar);
}

//Ximena
void SnakeGame::clearSnakeRegion()
{
	std::vector<COORD> body = snake.getBody();

	for (int i = 0; i < body.size(); i++)
	{
		writer.setCursorPosition(body.at(i));
		writer.setCharacterAtPosition(body.at(i), SpaceChar);
	}

}

//Sharmaine
void SnakeGame::playOneRound()
{
	if (ateApple()) {
		snake.increaseSnakeLength();
		player.increasePlayerScore();
		displayApple();
		displayScoreboard();
	}

	if (hitWall() || hitSelf()) {
		loseGame();
	}
}

//Sharmaine
bool SnakeGame::ateApple()
{
	std::vector<COORD> body = snake.getBody();
	return  (body.back().X == apple.getAppleCoord().X && body.back().Y == apple.getAppleCoord().Y);
}

//Sharmaine
void SnakeGame::loseGame()
{
	writer.clearRegion(mapRegionTopLeft, mapRegionBottomRight);
	writer.setCursorPosition(middleOfScreen);
	writer.write("GAME OVER");
	playAgain();
	
}

//Sharmaine
bool SnakeGame::hitWall()
{
	std::vector<COORD> body = snake.getBody();
	return (body.back().X <= topLeftMap.X || body.back().Y <= topLeftMap.Y ||
		body.back().X >= bottomRightMap.X || body.back().Y >= bottomRightMap.Y);
}


//Sharmaine
//If snake hits its own body
bool SnakeGame::hitSelf()
{
	std::vector<COORD> body = snake.getBody();
	COORD snakeHead = body.back();

	for (int i = body.size() - 2; i >= 0; i--)
	{
		if (body.at(i).Y == snakeHead.Y && body.at(i).X == snakeHead.X)
			return true;
	}
	return false;
}

//Sharmaine
void SnakeGame::playAgain()
{
	writer.setCursorPosition(underMiddleOfScreen);
	writer.writeLine("Press Y to play again or N to exit");
	writer.setCursorVisible(false);
	writer.setCursorPosition(underMiddleOfScreen.X, underMiddleOfScreen.Y + 1 );
	char response = reader.readCharacter();

	if (response == 'y' || response == 'Y') {
		player.setPlayerScore(0);
		snake.resetSnakeBody();
		start();
	}else {
		playing = false;
		return;
	}
}

