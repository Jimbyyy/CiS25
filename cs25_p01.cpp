#include <iostream>
#include<cstring>
#include <ctime>
using namespace std;

float rollDice(int minValue = -1000, int maxValue = 1000) {
    return((rand() % (maxValue - minValue + 1)) + minValue) / 10000.0;
}

void arrFiller(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        arr1[i] = arr2[i];
    }
}

void arrFiller(string arr1[], string arr2[], int size) {
    for (int i = 0; i < size; i++) {
        arr1[i] = arr2[i];
    }
}

void arrFiller(float arr1[], float arr2[], int size) {
    for (int i = 0; i < size; i++) {
        arr1[i] = arr2[i];
    }
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

class Business {
private:
    string name;
    int inventory[3] = { 0,0,0 };
    string items[3] = { "A","B","C" };
    float prices[3] = { 0,0,0 };
    float totalCash;
    float popularity;
public:
    Business(string name, string items[], int inventory[], float prices[], float totalCash, float popularity) {
        this->name = name;
        arrFiller(this->items, items, 3);
        arrFiller(this->inventory, inventory, 3);
        arrFiller(this->prices, prices, 3);
        this->totalCash = totalCash;
        this->popularity = popularity;
    }

    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }

    void setItems(int i, int item) {
        items[i] = item;
    }
    string getItems(int i) {
        return items[i];
    }

    void setPrices(int i, int price) {
        prices[i] = price;
    }
    float getPrices(int i) {
        return prices[i];
    }

    void setTotalCash(int cash) {
        totalCash = cash;
    }
    float getTotalCash() {
        return totalCash;
    }
    
    void setPopularity(float popularity) {
        this->popularity = popularity;
    }
    float getPopularity() {
        return popularity;
    }
};

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