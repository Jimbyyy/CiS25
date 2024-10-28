#include "cs25_a25.h"

int main() {

    Customer bob{
        1872653,
        "Bob",
        "bob@email.com",
        {
            "123 Park Blvd",
            "Berkeley",
            97485
        }
    };

    cout << "Customer ID: " << bob.id << endl
        << "Customer name: " << bob.name << endl
        << "Customer email: " << bob.email << endl
        << "Customer address: \n"
        << bob.address.street << ", "
        << bob.address.city << " "
        << bob.address.zipCode;

        return 0;
}