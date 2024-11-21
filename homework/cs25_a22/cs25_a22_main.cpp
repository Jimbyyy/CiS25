#include "cs25_a22.h"

int main() {
    string fullName;
    cout << "Enter your full name: ";
    getline(cin, fullName);

    extractFirstAndLastName(fullName);

    return 0;
}
