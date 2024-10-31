#ifndef CS25_A19_H
#define CS25_A19_H

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


#endif
