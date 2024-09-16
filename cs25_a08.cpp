// This program is forcing the divisor operator to return a double value via typecasting

#include <iostream>
using namespace std;

int main() {
    
    int x = 10;
    int y = 3;
    double z = static_cast<double>(x) / y;

    cout << z << endl;

    return 0;
}