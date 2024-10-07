#include <iostream>
#include <ctime>
using namespace std;


int main() {

    srand(time(0));
    double num = rand() % 100;
    double guess;

    cout << "Guess the random number between 0-99!" << endl;
    bool n = true;
        while (n) {
            cin >> guess;
            if (guess != num) {
                cout << "Wrong answer, try again!\n";
            }
            else {
                cout << "Correct!" << endl;
                n = false;
            }

        }

    return 0;
}