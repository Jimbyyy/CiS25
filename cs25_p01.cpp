#include <iostream>
#include<cstring>
#include <ctime>
using namespace std;

float rollDice(int minValue = -1000, int maxValue = 1000) {
    return((rand() % (maxValue - minValue + 1)) + minValue) / 10000.0;
}

class Customer;

class Stock {
private:
    string name;
    float price;
    float growth;
public:
    Stock(string name = "N/A", float price = 1.00, float growth = 1.00) {
        this->name = name;
        this->price = price;
        this->growth = growth;
    }

    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }

    void setPrice(float price) {
        this->price = price;
    }
    float getPrice() {
        return price;
    }

    void setGrowth(float growth) {
        this->growth = growth;
    }
    float getGrowth() {
        return growth;
    }

    double alterGrowth() {
        return(growth * rollDice());
    }
    void newPrice() {
        if (price > 0.10)
            setPrice(price + (price * alterGrowth()));
        else
            setPrice(1);
    }
};

class Business;

int main() {

    // rand() func seed
    srand(time(nullptr));

    Stock amk("amk", 100.00, 1.0);

    // testing output for stock object
    for (int i = 0; i < 1000; i++) {
        cout << "price: " << amk.getPrice() << endl;
        amk.newPrice();
        cout << "new price: " << amk.getPrice() << endl;
        cout << "--------" << endl;
    }

    // testing output of dice roller
    for (int i = 0; i < 100; i++) {
        cout << "Dice " << i << ": " << rollDice() << " || ";
    }

    return 0;
}