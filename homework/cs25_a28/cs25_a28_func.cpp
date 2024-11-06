#include "cs25_a28.h"

void doubleToString(double number){
    stringstream stream;
    stream << fixed << setprecision(1) << number;
    string str = stream.str();
    cout << str << endl;
}