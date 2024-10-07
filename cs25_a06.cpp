// This program takes user input to display formatted address

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string street;
    string city;
    string state;
    string zipCode;

    // Prompt the user for their address details
    cout << "Enter your street address: ";
    getline(cin, street);

    cout << "Enter your city: ";
    getline(cin, city);

    cout << "Enter your state: ";
    getline(cin, state);

    cout << "Enter your zip code: ";
    getline(cin, zipCode);

    // Print the formatted address
    cout << endl << "Your Address:" << endl;
    cout << street << endl;
    cout << city << ", " << state << " " << zipCode << endl;

    return 0;
}