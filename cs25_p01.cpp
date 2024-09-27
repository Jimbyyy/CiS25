#include <iostream>
#include<cstring>
#include <ctime>
#include <cmath>
using namespace std;

float rollDice(int minValue = -1000, int maxValue = 1000) {
    return((rand() % (maxValue - minValue + 1)) + minValue) / 100.0;
}

class Customer;
class Stock {
private:
    string name;
    float price;
    float growth;
public:
    Stock(string name = "N/A", float price = 0.00, float growth = 0.00) {
        this->name = name;
        this->price = price;
        this->growth = growth;
    }

    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return this->name;
    }

    void setPrice(float price) {
        this->price = price;
    }
    float getPrice() {
        return this->price;
    }

    void setGrowth(float price) {
        this->growth = growth;
    }
    float getGrowth() {
        return this->price;
    }

    void alterGrowth() {
        setGrowth(this->growth = (growth * rollDice()));
    }
    void newPrice() {
        setPrice(this->price = (price + (price * growth)));
    }
};
class Business;

int main() {

    // rand() func seed
    srand(time(nullptr));

    Stock amk("amk", 100.00, 1.0);

    // testing output for stock object
    for (int i = 0; i < 10; i++) {
        cout << "price: " << amk.getPrice() << endl;
        amk.alterGrowth();
        amk.newPrice();
        cout << "price: " << amk.getPrice() << endl;
        cout << "growth: " << amk.getGrowth() << endl;
        cout << "--------" << endl;
    }

    // testing output of dice roller
    for (int i = 0; i < 100; i++) {
        cout << "Dice " << i << ": " << rollDice() << endl;;
    }

    return 0;
}