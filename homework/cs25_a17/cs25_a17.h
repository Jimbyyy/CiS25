#ifndef CS_25A17_H
#define CS_25A17_H

int linearSearch(int arr[], int size, int searchValue) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchValue)
        return i;
    }
    return -1;
}

#endif