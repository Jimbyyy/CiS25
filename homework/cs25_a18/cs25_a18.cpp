#include <iostream>
#include "cs25_a18.h"
using namespace std;

int main(){

    const int SIZE = 7;
    int arr[SIZE] = { 6, 3, 7, 5, 2, 4, 1 };
    numSort(arr, SIZE);
    
    for (int x : arr) {
    cout << "Sorted array: " << x;
    }
    
    return 0;
}