// This program prints stars based on user input

#include <iostream>
using namespace std;

// Prints n stars in a line
void printStarLine(int n) {
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
}

int main (){

    int num;
    cout << "Please enter how many lines of stars you would like to print: " << endl;
    cin >> num;
    for (int i = 0; i <= num; i++) {
        printStarLine(i);
    }
}