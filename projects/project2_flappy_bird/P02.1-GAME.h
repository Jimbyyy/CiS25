#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;

struct Pipe {
	int xCoord;
	int topHeight;
	int bottomHeight;
};

// ANSI clear terminal command
void clear();

// Displays the gamefield
void updateDisplay(const int HEIGHT, const int WIDTH, int& birdYCoord, int& numPipes, Pipe pipes[], int& score);

// Calculates bird physics
void birdLogic(const int HEIGHT, const int WIDTH, int& birdYCoord, int& birdVelocity);

// Handles Pipe generation and deletion
void pipeLogic(const int HEIGHT, const int WIDTH, int& birdYCoord, int& birdVelocity, int& numPipes, Pipe pipes[], bool& gameOver, int& score);

// Grabs user input and jump bird
void input(int& birdVelocity);

//void readHighScore();
//
//void writeHighScore();