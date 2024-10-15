#include <iostream>
#include "cs25_a20.h"
using namespace std;

int main() {

    int n = 0;
    int size = 5;
    int* arrOrigin = new int[size];

    while (true) {

        int userNum = 0;
        cout << "input a number: ";
        cin >> userNum;

        if (userNum == -999) {
            cout << "exiting array..." << endl;
            break;
        }
        else if (n > size - 1) {
            cout << "increaseing array size..." << endl;
            size *= 2;
            int* arrDouble = new int[size];
            copyArr(arrOrigin, arrDouble, n);
            delete[] arrOrigin;
            arrOrigin = arrDouble;
        }

        arrOrigin[n] = userNum;
        n++;
    }

    displayArr(arrOrigin, n);
    sumArr(arrOrigin, n);

    delete[] arrOrigin;
    arrOrigin = nullptr;

    return 0;

}