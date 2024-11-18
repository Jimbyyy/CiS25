/*
Project 2: Flappy Bird
----------------------
Things to do:
- Create pipes [x]
- Create display [x]
- Create input [x]
- Create game logic [x]
- Create score tracker [x]

- Create score saver []
	- Need parallel arrays for name and score
		- Will read this to text file for permanant saves
	- Will use dynamic memory and pointers to extract txt files into dynamic arrays for display
		- Will display name and score
	- Will use optimized bubblesort to rearrange scores from greatest to least
		- Will grab top score for display during gameplay
- Create difficulty settings []
	- Use enumerations to alter global variables
		- Use a switch-case to determine the right settings for user.

----------------------
*/

#include "P02.1-GAME.h"

// Game constants
const int HEIGHT = 20;
const int WIDTH = 40;

// Global game variables
int birdYCoord = HEIGHT / 2;
int birdVelocity = 0;
int score = 0;
bool gameOver = false;
Pipe pipes[10];
int numPipes = 0;

int main() {

	srand(time(nullptr));
	while(true) {

		while (!gameOver) {
			updateDisplay(HEIGHT, WIDTH, birdYCoord, numPipes, pipes, score);
			input(birdVelocity);
			birdLogic(HEIGHT, WIDTH, birdYCoord, birdVelocity);
			pipeLogic(HEIGHT, WIDTH, birdYCoord, birdVelocity, numPipes, pipes, gameOver, score);
		}

		clear();
		cout << "Game Over! Your final score is: " << score << endl;

	}

	return 0;
}