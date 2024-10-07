// This program compares integer values

#include <iostream>
using namespace std;

int main() {
    
    double value1, value2, largerValue;

    cout << "Enter the first value: ";
    cin >> value1;

    cout << "Enter the second value: ";
    cin >> value2;

    // Determine the larger value using if statement
    if (value1 > value2) {
        largerValue = value1;
    } else {
        largerValue = value2;
    }

    cout << "The larger value is: " << largerValue << endl;

    // Determine the larger value using conditional statement
    largerValue = ((value1 > value2) ? value1 : value2);

    cout << "The larger value is: " << largerValue << endl;
    
    return 0;
}
