#include "cs25_a23.h" 

int main() {

    string customerNumber;

    // Test case
    cout << "Enter customer number: ";
    cin >> customerNumber;

    if (isValidCustomerNumber(customerNumber)) {
        cout << "Valid customer number.\n";
    }
    else {
        cout << "Invalid customer number.\n";
    }

    return 0;

}
