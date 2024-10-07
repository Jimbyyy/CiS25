// This program does linear search

#include <iostream>
#include "cs25_a17.h""
using namespace std;

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