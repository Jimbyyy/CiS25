// This program rolls dice

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Generates a random number in the range [minValue, maxValue]
int rollDice(int minValue, int maxValue) {
	return(rand() % (maxValue - minValue + 1)) + minValue;
}

int main()
{
	// generating random seed for rand() func
	long seed = time(0);
	srand(seed);
	
	int minValue = 5;
	int maxValue = 20;
	
	// test cases
	for (int n = 0; n < 5; n++) {
		int die = rollDice(minValue, maxValue);
		cout << "\nDie " << n+1 << ": " << die;
	}

	return 0;
}