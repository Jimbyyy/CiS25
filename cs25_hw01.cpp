// This program converts integers values into binary

#include <iostream>
using namespace std;

// returns the exponent product of an integer input
int pow(int num, int exp) {
    int product = 1;
    for (int i = 0; i < exp; i++) {
        product = (product * num);
    }

    return product;
}

// returns the absolute value of an integer input
int absVal(int num) {
    if (num < 0)
        return -num;
    else
        return num;
}

// converts integer values to signed binary
void binaryConverter(int num, int binArr[9]) {

        // bounds checking
    if (absVal(num) > 255) {
        cout << "OVERFLOW ERROR\n";
        return;
    }
    
    // signed bit assignment
    if (absVal(num) != num) {
        binArr[0] = 1;
    }
    else {
        binArr[0] = 0;
    }

    // base 2 bit assignment
    int n = 7;
    for (int i = 1; i < 9; i++) {
        //cout << "\nIteration n is: " << n << endl; <-- ignore this test code comment
        if (absVal(num) >= pow(2, n)) {
            binArr[i] = 1;
            num = num - pow(2, n);
            n--;
        }
        else {
            n--;
        }
    }
}

// displays array values to console
void arrDisplay(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
    }
}

int main() {

    const int SIZE = 9;
    int binArr[SIZE] = { 0,0,0,0,0,0,0,0,0 };
    int num;

    cout << "Please input an integer value between -255 to 255: ";
    cin >> num;
    cout << "\nInput read, processing....\n";
    binaryConverter(num, binArr);
    cout << "\nConverted Binary Value is: 0b";
    arrDisplay(binArr, SIZE);
    cout << endl;

    return 0;
}