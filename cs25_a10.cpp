// This program calculates commisions based on salary amount

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    double sales;
    double commission;

    // Prompt the user to enter the sales amount
    cout << "Enter the total sales amount: $";
    cin >> sales;

    // Determine the commission based on the sales amount
    if (sales <= 10000) {
        commission = sales * 0.10;
    } else if (sales <= 15000) {
        commission = sales * 0.15;
    } else {
        commission = sales * 0.20;
    }

    cout << fixed << setprecision(2);
    cout << "The commission is: $" << commission << endl;

    return 0;
}
