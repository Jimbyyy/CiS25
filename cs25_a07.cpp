// This program prmopts for 3 names and prints the first one

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string names[3];

    cout << "Enter the first name: ";
    getline(cin, names[0]);

    cout << "Enter the second name: ";
    getline(cin, names[1]);

    cout << "Enter the third name: ";
    getline(cin, names[2]);

    cout << "The first name is: " << names[0] << endl;

    return 0;
}
