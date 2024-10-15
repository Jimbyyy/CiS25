#include <iostream>
using namespace std;

// copies values from orignal array to a new array
void copyArr(int arrOrigin[], int arrNew[], int size) {
    for (int i = 0; i < size; i++) {
        arrNew[i] = arrOrigin[i];
    }
}

// sums the values in an array
void sumArr(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << "sum is: " << sum << endl;
}

// displays integer array values to terminal
void displayArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " || ";
    }
    cout << endl;
}
