// this program compares student scores

#include <iostream>
#include "cs25_a16.h"
using namespace std;

int main() {

    int size = 0;
    int avg = 0;

    cout << "How many students scores are you inputting?: ";
    cin >> size;

    int* arrScore = new int[size];
    string* arrStudents = new string[size];

    for (int i = 0; i < size; i++) {
        string name = "N/A";
        int score = 0;
        int avg = 0;

        cout << "Please input student" << i + 1 << "'s name: ";
        cin >> name;
        cout << "Please input student" << i + 1 << "'s score: ";
        cin >> score;
        arrStudents[i] = name;
        arrScore[i] = score;
    }

    sortArr(arrScore, arrStudents, size);
    avg = avg::grade(arrScore, size);

    cout << "\n\nHere is your generated student score statistics: " << endl
        << "===================================================" << endl;

    cout << "Max score: " << max::grade(arrScore, size) << endl;
    cout << "Min score: " << min::grade(arrScore) << endl;
    cout << "Average score: " << avg << endl;

    cout << "\n\nThe following students were above average: ";
    aboveAverage::grade(arrScore, arrStudents, avg, size);

    cout << "\n\nSTUDENT DATA: " << endl;
    displayArr(arrScore, arrStudents, size);

    while (true) {
        int n = 0;

        cout << "\n\nWould you like to compare student scores?"
            << "\nType 1 for yes or 2 for no: ";
        cin >> n;

        if (n == 1) {
            string student1;
            string student2;
            cout << "Which students would you like to compare? Please enter both their names";
            cin >> student1, student2;
            compare::grade(arrScore, arrStudents, size, student1, student2);
        }
        else if (n == 2) {
            break;
        }
        else {
            cout << "ERROR: Input nonvalid; please try again: ";
            cin >> n;
        }

    }

    return 0;
}