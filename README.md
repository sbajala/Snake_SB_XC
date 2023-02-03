# Snake Game

A C++ console-based version of the classic arcade game Snake.

## Usage

### Screen
The screen is composed of:
- Player information: It is the rectangle in the top when you can see player's name, actual score and the lenght of the snake.
- Game Region: Above the Player Information, there is a rectangle wich delimits the area where the snake can moves. 
- The game sets the size of the screen by default.

### How Play
### To Start
- The player must type their name and press enter key.
- The snake will be positioned at middle of the screen and it automatically starts to move right-forward.
- An apple represented with the "ó" character, will be positionated ramdomly in the Game Region.
### Playing
- Use arrow keys to move the head of the snake.
- If the snake hits an apple:
	- The snake grows (becomes longer).
	- A new apple appears at a new random location.
	- The player's score increase by one.
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
