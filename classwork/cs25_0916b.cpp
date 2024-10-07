// program gets the average of temperatures submitted by users

#include <iostream>
using namespace std;

// gets the average of the numeric values in an array
double getAvg(float arr[], int size) {
    double avg = 0;
    int i;
    for (i = 1; i < size; i++) {
        avg += arr[i - 1] + arr[i];
    }
    avg = static_cast<double>(avg) / (i + 1);
    return avg;
}

// asks user to fill array with numeric values
void fillArr(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter temp " << i + 1 << ": " << endl;
        cin >> arr[i];
    }
}

int main() {

    // defining array size
    int size = 0;
    cout << "how many temperatures will you input?: ";
    cin >> size;

    float* tempArr = new float[size];
    fillArr(tempArr, size);

    cout << "Average of temperatures is: " << getAvg(tempArr, size);
    delete[] tempArr;

    return 0;
}