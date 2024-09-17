// this program calculates the factorial of an inputed integer

#include <iostream>
using namespace std;

// recursively calculates the facotrial of an input
int factorial(int n) {
    int num;
    if (n == 0)
        num = 1;
    else if (n > 0) {
        num = n * factorial(n - 1);
        return num;
    }
    else
        return 1;
}

int main() {

    int num;
    cout << "Please input a positive integer: ";
    cin >> num;
    cout << "Factorial: " << factorial(num);

    return 0;
}