// This program that checks whether an applicant is eligible for a job

#include <iostream>
using namespace std;

int main() {
    
    bool citizenship;
    bool hasBachelorDegree;
    int yearsOfExperience;

    cout << "Are you a US citizen? (1 for yes, 0 for no): ";
    cin >> citizenship;

    cout << "Do you have a bachelor's degree? (1 for yes, 0 for no): ";
    cin >> hasBachelorDegree;

    cout << "How many years of experience do you have? ";
    cin >> yearsOfExperience;

    // Check eligibility
    if ((citizenship) && (hasBachelorDegree || (yearsOfExperience >= 2))) {
        cout << "You are eligible for the job." << endl;
    } 
    else {
        cout << "You are not eligible for the job." << endl;
    }

    return 0;
}
