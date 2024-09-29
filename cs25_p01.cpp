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
    int inventory[3];
    string items[3];
    float prices[3];
    float totalCash;
    float popularity;
public:
    Business(string name, string items[3], int inventory[3], float prices[3], float totalCash = 1000, float popularity = 100) {
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

    void buyStock(Stock stock, int num, int itemNum) {
        if ((totalCash >= (num * stock.getPrice())) && (items[itemNum] == stock.getName())) {
            setTotalCash(totalCash - (num * stock.getPrice()));
            inventory[itemNum] += num;
        }
        else
            cout << "ERROR, not enough money or wrong stock!" << endl;
    }

    void sellStock(Stock stock, int num, int itemNum) {
        if ((items[itemNum] == stock.getName()) && inventory[itemNum] > 0) {
            setTotalCash(totalCash + (num * stock.getPrice()));
            inventory[itemNum] -= num;
        }
        else
            cout << "ERROR, not enough money or stock!" << endl;
    }

    void advertise(int cash) {
        if (cash > 50 + (0.01 * popularity))
            setPopularity(popularity + 10);
        else
            cout << "ERROR, not enough cash!" << endl;
    }

    /*
    Business should have the following functionalities:
    ==================================
    - ability to buy inventory
    - ability to sell inventory
    - ability to set prices
    - ability to advertise
    ===================================
    */

};

int main() {

    // rand() func seed
    srand(time(nullptr));

    // test stocks
    Stock amk("amk", 100.00, 1.0);
    Stock crack("crack", 100.00, 100),
        jello("jello", 30, 3),
        pinapple("pinapple", 5, 1);

    // test business parameters
    int inventory[3] = { 0,0,0 };
    string items[3] = { "crack","jello","pinapple" };
    float prices[3] = { 0,0,0 };

    Business shop("Lmabdacore", items, inventory, prices, 1000, 100);

    // testing business functions
    cout << shop.getName() << endl;
    shop.buyStock(crack, 10, 0);
    cout << shop.getTotalCash() << endl;
    crack.newPrice();
    shop.sellStock(crack, 10, 0);
    cout << shop.getTotalCash() << endl;

    // testing output for stock object
     for (int i = 0; i < 10; i++) {
         cout << "price: " << crack.getPrice() << endl;
         crack.newPrice();
         cout << "new price: " << crack.getPrice() << endl;
         cout << "--------" << endl;
     }

    // testing output of dice roller
    // for (int i = 0; i < 10; i++) {
    //     cout << "Dice " << i << ": " << rollDice() << " || ";
    // }

    return 0;
}