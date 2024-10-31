#ifndef CS25_A21_H
#define CS25_A21_H

#include <iostream>
#include <memory>
using namespace std;

// copies values from orignal array to a new array
void copyArr(shared_ptr<int[]> &arrOrigin, shared_ptr<int[]> &arrNew, int size);

// sums the values in an array
void sumArr(shared_ptr<int[]> &arr, int size);

// displays integer array values to terminal
void displayArr(shared_ptr<int[]> &arr, int size);

#endif