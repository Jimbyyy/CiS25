// This program displays datatype size and bounds

#include <iostream>
using namespace std;

int main() {
    
    cout << "short bit size: " << sizeof(short) << endl
        << numeric_limits<short>::max() << endl
        << numeric_limits<short>::min() << endl;

     cout << "double bit size: " << sizeof(double) << endl
        << numeric_limits<double>::max() << endl
        << numeric_limits<double>::min() << endl;
    
    return 0;
}