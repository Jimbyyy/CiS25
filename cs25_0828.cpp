#include <iostream>
using namespace std;

int main() {
	// Initializing variables
	int num1 = 1;
	int num2 = 2;
	int temp = 0;
	cout << "num1: " << num1
		 << "\nnum2: " << num2;

	// Swapping variables
	temp = num1;
	num1 = num2;
	num2 = temp;
	cout << "\n\nSwapped: "
		<< "\nnum1: " << num1
		<< "\nnum2: " << num2;
}