#include "cs25_a24.h"
using namespace std;

int main(){

    Customer bob;

    cout << "Please input an id: ";
    cin >> bob.id;

    cout << "Please input an name: ";
    cin >> bob.name;

    cout << "Please input an email: ";
    cin >> bob.email;

    cout << "Customer ID: " << bob.id << endl
    << "Customer name: " << bob.name << endl
    << "Customer email: " << bob.email << endl;

    return 0;
}