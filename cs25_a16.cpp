// this program compares student scores

#include <iostream>
using namespace std;

namespace max
{
    int grade(int score[], int size) {
        int max = score[size - 1];
        return max;
    }
}
namespace min
{
    int grade(int score[]) {
        int min = score[0];
        return min;
    }
}
namespace avg
{
    int grade(int score[], int size) {
        int avg = 0;
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += score[i];
        }
        avg = sum / size;
        return avg;
    };
}
namespace aboveAverage
{
    void grade(int score[], string student[], int avg, int size) {
        for (int i = 0; i < size; i++) {
            if (score[i] >= avg) {
                cout << student[i] << " ";
            }
        }
    };
}
namespace compare
{
    void grade(int score[], string name[], int size, string stud1, string stud2) {
        int index1 = 0;
        int index2 = 0;
        for (int i = 0; i < size; i++) {
            if (stud1 == name[i]) {
                index1 = i;
            }
            if (stud2 == name[i]) {
                index2 = i;
            }
        }

        if (score[index1] > score[index2]) {
            cout << "Student " << name[index1] << " has a higher score than " << name[index2];
        }
        else {
            cout << "Student " << name[index2] << " has a higher score than " << name[index1];
        }
    }
}

// sorts linked arrays of strings and ints from lowest to highest
void sortArr(int score[], string student[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size - 1; j++) {
            if (score[i] < score[j]) {
                int temp1 = score[i];
                score[i] = score[j];
                score[j] = temp1;

                string temp2 = student[i];
                student[i] = student[j];
                student[j] = temp2;
            }
        }
    }
}

// displays students names and scores from an array
void displayArr(int score[], string names[], int size) {
    for (int i = 0; i < size; i++) {
        cout << names[i] << " - " << score[i] << endl;
    }
}

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

        cout << "The following students were above average: ";
        aboveAverage::grade(arrScore, arrStudents, avg, size);

        cout << "\nSTUDENT DATA: " << endl;
        displayArr(arrScore, arrStudents, size);

        while (true) {
            int n = 0;

            cout << "Would you like to compare student scores?"
                << "/nType 1 for yes or 2 for no: ";
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