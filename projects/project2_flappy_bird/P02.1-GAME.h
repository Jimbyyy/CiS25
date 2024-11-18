#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;

// Game constants
const int HEIGHT = 20;
const int WIDTH = 40;

// Bird Properties
extern int birdYCoord;
extern int birdVelocity;
extern bool gameOver;
extern int score;

struct Pipe {
	int xCoord;
	int topHeight;
	int bottomHeight;
};

// ANSI clear terminal command
void clear();

// Displays the gamefield
void updateDisplay();

// Calculates bird physics
void birdLogic();

// Handles Pipe generation and deletion
void pipeLogic();

// Grabs user input
void input();

//void readHighScore();
//
//void writeHighScore();