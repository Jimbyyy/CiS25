// This program prints a table with 2 coulumns and 2 rows

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Print table header
    cout << left << setw(15) << "Course" 
         << right << setw(15) << "Student" << endl;

    // Print table rows
    cout << left << setw(15) << "C++"
         << right << setw(15) << 100 << endl;

    cout << left << setw(15) << "JavaScript"
         << right << setw(15) << 50 << endl;

    return 0;
}