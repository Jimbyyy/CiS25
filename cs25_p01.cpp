#include <iostream>
#include <iomanip>
#include<cstring>
#include <ctime>
using namespace std;

const int SIZE = 3;

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

// function doesn't work >:<
//float getNetWorth(const Business &shop, Stock stocks[3]) {
//    float stockWorth = 0;
//    float netWorth = 0;
//    for (int i = 0; i < 3; i++) {
//        stockWorth += shop.getInventory(i) * stocks[i].getPrice();
//    }
//    netWorth += shop.getCash() + stockWorth;
//    return netWorth;
//}

// cut from project due to scope-creep
// class Customer;

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
        float alterPrice = (price + (price * alterGrowth()));
        if (alterPrice >= 0.10)
            setPrice(alterPrice);
        else
            setPrice(1);
    }
};

class Business {
private:
    string name;
    int inventory[SIZE];
    string items[SIZE];
    float prices[SIZE];
    float cash;
    float popularity;
public:
    Business(string name, string items[SIZE], int inventory[SIZE], float prices[SIZE],
        float cash = 1000, float newWorth = 1000, float popularity = 100) {
        this->name = name;
        arrFiller(this->items, items, SIZE);
        arrFiller(this->inventory, inventory, SIZE);
        arrFiller(this->prices, prices, SIZE);
        this->cash = cash;
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

    void setInventory(int i, int num) {
        inventory[i] = num;
    }
    int getInventory(int i) {
        return inventory[i];
    }

    void setPrices(int i, int price) {
        prices[i] = price;
    }
    float getPrices(int i) {
        return prices[i];
    }

    void setCash(int cash) {
        this->cash = cash;
    }
    float getCash() {
        return cash;
    }

    void setPopularity(float popularity) {
        this->popularity = popularity;
    }
    float getPopularity() {
        return popularity;
    }

    void buyStock(Stock stock, int num, int itemNum) {
        if ((cash >= (num * stock.getPrice())) && (items[itemNum] == stock.getName())) {
            setCash(cash - (num * stock.getPrice()));
            inventory[itemNum] += num;
        }
        else
            cout << "ERROR, not enough money or wrong stock!" << endl;
    }

    void sellStock(Stock stock, int num, int itemNum) {
        if ((items[itemNum] == stock.getName()) && inventory[itemNum] > 0) {
            setCash(cash + (num * stock.getPrice()));
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

void displayMenu() {
    cout << "\n=== Stock Market Menu ===" << endl;
    cout << "1. Buy Stock" << endl;
    cout << "2. Sell Stock" << endl;
    cout << "3. View Business Info" << endl;
    cout << "4. Exit" << endl;
    cout << "=========================" << endl;
    cout << "Choose an option: ";
}

int main() {

    // rand() func seed
    srand(time(nullptr));

    // test stocks
    Stock crack("crack", 100.00, 100),
        jello("jello", 30, 10),
        pinapple("pinapple", 5, 1);

    // test business parameters
    string name;
    int inventory[SIZE] = { 0,0,0 };
    string items[SIZE] = { "crack","jello","pinapple" };
    float prices[SIZE] = { 0,0,0 };
    Stock stocks[SIZE] = { crack, jello, pinapple };
    float startingCash = 1000;
    float startingPopulartity = 100;

    cout << "Hello, welcome to the stock market simulator. Will you rise to riches or fall to rags?\n";
    cout << "=========================================================================================" << endl;
    cout << "First of all, what will your stock empire be called?: ";
    cin >> name;
    cout << "\nOkay, " << name << " you've been blessed by your parents and offered $1000 of cash to start with!"
        << "\nThere are 3 primary stocks on the market: crack, jello, and pinapple corps. to name!"
        << "\nCrack co. is a cutting-edge, black market company run by illegal organizations, "
        << "and thus suffers from the highest amount of volataility"
        << "\nJello incorporated, are a trendy, innovative company known for their unique products, they have medium volatility"
        << "\nPinapple is a traditional mass market distributer, and is known to be quite stable with low volatility"
        << "\nOkay, good luck out there! Initializing stock ui interface now... " << endl;

    Business shop(name, items, inventory, prices, startingCash, startingPopulartity);

    int dayCount = 0;
    while (dayCount < 1) {
        cout << left << setw(20) << dayCount << endl;
        cout << left << setw(20) << "Business Name" << ": " << shop.getName() << endl;
        cout << left << setw(20) << "Cash" << ": $" << shop.getCash() << endl;

        cout << "\n" << left << setw(20) << "Item" << setw(15) << "Inventory" << setw(15) << "Price" << endl;
        cout << "--------------------------------------------------" << endl;

        for (int i = 0; i < SIZE; i++) {
            cout << left << setw(20) << shop.getItems(i)
                << setw(15) << shop.getInventory(i)
                << "$" << setw(14) << (shop.getInventory(i) * stocks[i].getPrice()) << endl;
        }

        displayMenu();
        dayCount++;
       
        for (int i = 0; i < SIZE; i++) {
            stocks[i].newPrice();
        }
    }

    // testing business functions
    cout << shop.getName() << endl;
    shop.buyStock(crack, 10, 0);
    cout << shop.getCash() << endl;
    crack.newPrice();
    shop.sellStock(crack, 10, 0);
    cout << shop.getCash() << endl;

    // testing output for stock object
    for (int i = 0; i < 100; i++) {
        cout << "price: " << crack.getPrice() << endl;
        crack.newPrice();
        cout << "new price: " << crack.getPrice() << endl;
        cout << "--------" << endl;
    }

    // testing output of dice roller
    for (int i = 0; i < 10; i++) {
        cout << "Dice " << i << ": " << rollDice() << " || ";
    }

    return 0;
}