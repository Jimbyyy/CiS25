#include "cs25_a17.h"

int linearSearch(int arr[], int size, int searchValue) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchValue)
        return i;
    }
    return -1;
}