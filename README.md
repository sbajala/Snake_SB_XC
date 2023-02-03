# Snake Game

A C++ console-based version of the classic arcade game Snake.

## Usage

### Screen
The screen is composed of:
- Player information: It is the rectangle at the top where you can see the player's name, actual score and the lenght of the snake.
- Game Region: Above the player's information, there is a rectangle wich delimits the area where the snake can move. 
- The game sets the size of the screen by default.

### How Play
### To Start
- The player must type their name and press the 'enter' key.
- The snake will be positioned at middle of the screen and it automatically starts to move rightward.
- An apple represented with the "ó" character will be positionated randomly within the Game Region.
### Playing
- Must use the arrow keys to move the head of the snake.
- If the snake hits an apple:
	- The snake grows (becomes longer).
	- A new apple appears at a new random location.
	- The player's score increases by one.
### Losing conditions:
- If the snake hits a wall.
- If the snake hits itself.
### Victory Conditions
- The goal is to continue playing as long as possible, until the player loses.

## To Consider:
This is a console game, and the players could see some errors:
- The snake is slow.
- Sometimes the users must clear the input before typing a new input.
- Users can change the size of the screen
