#include "cs25_a22.h"

void extractFirstAndLastName(const string& fullName) {
    size_t spacePos = fullName.find(' ');

    string firstName = fullName.substr(0, spacePos);
    string lastName = fullName.substr(spacePos + 1);

    // Output the first and last name
    cout << "First name: " << firstName << endl;
    cout << "Last name: " << lastName << endl;

}
