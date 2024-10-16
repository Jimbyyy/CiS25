#include <iostream>
#include <memory>
#include "cs25_a21.h"
using namespace std;

int main() {

    int n = 0;
    int size = 5;
    shared_ptr<int[]> arrOrigin(new int[size]);

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
            shared_ptr<int[]> arrDouble(new int[size]);
            copyArr(arrOrigin, arrDouble, n);
            arrOrigin = arrDouble;
        }

        arrOrigin[n] = userNum;
        n++;
    }

    displayArr(arrOrigin, n);
    sumArr(arrOrigin, n);

    return 0;

}