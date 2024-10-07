// This program does linear search

#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int searchValue) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchValue)
        return i;
    }
    return -1;
}

int main() {
int array[] = {2, 4, 0, 1, 9};
int x = 1;
int n = sizeof(array) / sizeof(array[0]);
int result = linearSearch(array, n, x);
if (result == -1)
cout << "Element not found\n";
else
cout << "Element found at index: " << result << endl;
return 0;
}