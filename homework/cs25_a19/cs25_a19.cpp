// this program swaps numbers with pointers

#include <iostream>
#include "cs25_a19.h"
using namespace std;
int main() {

    int num1 = 20;
    int num2 = 40;

    cout << "Num1: " << num1
        << "\nNum2: " << num2;

    swap(&num1, &num2);

    cout << "\n\nNum1: " << num1
        << "\nNum2: " << num2 << endl;

    return 0;

}