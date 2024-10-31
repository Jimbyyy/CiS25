#include "cs25_a19.h"

// swaps variable values with pointers
void swap(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void swap(double* ptr1, double* ptr2) {
    double temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void swap(char* ptr1, char* ptr2) {
    char temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}