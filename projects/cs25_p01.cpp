#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctime>
using namespace std;

const int SIZE = 3;

// by default generates decimal values between -0.01 and +0.01
// additional digits for increased level of precision
float rollDice(int minValue = -1000, int maxValue = 1000) {
    return static_cast<float>((rand() % (maxValue - minValue + 1)) + minValue) / 10000;
}

// returns the absolute value of an float input
float absVal(float num) {
    if (num < 0)
        return -num;
    else
        return num;
}

// takes the values of one array to fill another of the same size
void arrFiller(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        arr1[i] = arr2[i];
    }
}
// takes the values of one array to fill another of the same size
void arrFiller(string arr1[], string arr2[], int size) {
    for (int i = 0; i < size; i++) {
        arr1[i] = arr2[i];
    }
}
// takes the values of one array to fill another of the same size
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
    // constructor
    Stock(string name = "N/A", float price = 1.00, float growth = 1.00) {
        this->name = name;
        this->price = price;
        this->growth = growth;
    }

    // changes the name of stock
    void setName(string name) {
        this->name = name;
    }
    // returns the name of stock
    string getName() {
        return name;
    }

    // changes the price of stock
    void setPrice(float price) {
        this->price = price;
    }
    // returns price of stock
    float getPrice() {
        return price;
    }

    // changes growth rate of stock
    void setGrowth(float growth) {
        this->growth = growth;
    }
    // returns growth rate of stocks
    float getGrowth() {
        return growth;
    }

    // returns a randomized stock percentage growth rate
    double alterGrowth() {
        return(growth * rollDice());
    }
    // generates and sets a new price for stock
    void newPrice() {
        float alterPrice = (price + (price * alterGrowth()));
        if (alterPrice >= 0.01)
            setPrice(alterPrice);
        else
            setPrice(absVal(rollDice() * 10));
    }

    ~Stock() {};
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
    // constructor
    Business(string name, string items[SIZE], int inventory[SIZE], float prices[SIZE],
        float cash = 1000, float newWorth = 1000, float popularity = 100) {
        this->name = name;
        arrFiller(this->items, items, SIZE);
        arrFiller(this->inventory, inventory, SIZE);
        arrFiller(this->prices, prices, SIZE);
        this->cash = cash;
        this->popularity = popularity;
    }

    // changes name of business
    void setName(string name) {
        this->name = name;
    }
    // returns name of business
    string getName() {
        return name;
    }

    // changes item name of item i
    void setItems(int i, string item) {
        items[i] = item;
    }
    // returns name of item i
    string getItems(int i) {
        return items[i];
    }

    // changes inventory of item i by amount num
    void setInventory(int i, int num) {
        inventory[i] = num;
    }
    // returns inventory of item i
    int getInventory(int i) {
        return inventory[i];
    }

    // changes price of item i to input price
    void setPrices(int i, int price) {
        prices[i] = price;
    }
    // returns price of item i
    float getPrices(int i) {
        return prices[i];
    }

    // changes cash to input amount
    void setCash(int cash) {
        this->cash = cash;
    }
    // returns cash amount
    float getCash() {
        return cash;
    }

    // change popularity to input amount
    void setPopularity(float popularity) {
        this->popularity = popularity;
    }
    // returns popularity value
    float getPopularity() {
        return popularity;
    }

    // finds and buys stock based on cash and name
    void buyStock(Stock stock, int num, int itemNum) {
        if ((cash >= (num * stock.getPrice())) && (items[itemNum] == stock.getName())) {
            setCash(cash - (num * stock.getPrice()));
            inventory[itemNum] += num;
        }
        else
            cout << "ERROR, not enough money or wrong stock!" << endl;
    }

    // finds and sells stock based on inventory and name
    void sellStock(Stock stock, int num, int itemNum) {
        if ((items[itemNum] == stock.getName()) && inventory[itemNum] > 0) {
            setCash(cash + (num * stock.getPrice()));
            inventory[itemNum] -= num;
        }
        else
            cout << "ERROR, not enough money or stock!" << endl;
    }

    // spend cash to increase popularity
    void advertise(int cash) {
        if (cash > 50 + (0.01 * popularity))
            setPopularity(popularity + 10);
        else
            cout << "ERROR, not enough cash!" << endl;
    }

    ~Business() {};
};

// displays ui menu for user
void displayMenu() {
    cout << "\n=== Stock Market Menu ===" << endl;
    cout << "1. Buy Stock" << endl;
    cout << "2. Sell Stock" << endl;
    cout << "3. View Business Info" << endl;
    cout << "4. Sleep To Tommorow" << endl;
    cout << "5. Exit Game" << endl;
    cout << "=========================" << endl;
    cout << "Choose an option (input a number): ";
}

// displays intro blurb to user
void displayIntro(string& name) {
    cout << "Hello, welcome to the stock market simulator. Will you rise to riches or fall to rags?\n";
    cout << "=========================================================================================" << endl;
    cout << "First of all, what will your stock empire be called?: ";
    cin >> name;
    cout << "\nOkay, " << name << " you've been blessed by your parents and offered $1000 of cash to start with!"
        << "\nThey don't trust you however, so you must train yourself first in the virtual world..."
        << "\nThere are 3 primary stocks on this market: crack, jello, and pinapple corps. to name!"
        << "\nCrack co. is a cutting-edge, black market company run by illegal organizations, "
        << "\nand thus suffers from the highest amount of volataility"
        << "\nJello incorporated, are a trendy, innovative company known for their unique products, they have medium volatility"
        << "\nPinapple is a traditional mass market distributer, and is known to be quite stable with low volatility"
        << "\nOkay, good luck out there! Initializing stock ui interface now... \n" << endl;
}

int main() {

    // rand() func seed
    srand(time(nullptr));

    // stocks
    Stock crack("crack", 100.00, 32),
        jello("jello", 100.00, 16),
        pinapple("pinapple", 100.00, 8);

    // business parameters
    string name = "N/A";
    int inventory[SIZE] = { 0,0,0 };
    string items[SIZE] = { "crack","jello","pinapple" };
    float prices[SIZE] = { 0,0,0 };
    Stock stocks[SIZE] = { crack, jello, pinapple };
    float startingCash = 1000;
    float startingPopulartity = 100;

    displayIntro(name);

    Business shop(name, items, inventory, prices, startingCash, startingPopulartity);

    int dayCount = 0;
    int choice = 0;

    // initial businessInfoDisplay
    // ideally this'd be a businessInfoDisplay function, however I get errors when trying to access
    // access a Business object's parameters in a function, hence I must manually print output
    cout << left << setw(20) << "Day" << ": " << dayCount << endl;
    cout << left << setw(20) << "Business Name" << ": " << shop.getName() << endl;
    cout << left << setw(20) << "Cash" << ": $" << shop.getCash() << endl;

    cout << "\n" << left << setw(20) << "Item" << setw(15) << "Inventory" << setw(15) << "Price" << setw(15) << "Holdings" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << fixed << setprecision(2)
            << left << setw(20) << shop.getItems(i)
            << setw(15) << shop.getInventory(i)
            << "$" << setw(14) << stocks[i].getPrice()
            << "$" << setw(14) << (shop.getInventory(i) * stocks[i].getPrice())
            << endl;
    }

    // Primary game loop
    while (true) {

        displayMenu();
        cin >> choice;

        if (choice == 1) {
            string stockName;
            int quantity;
            cout << "Enter the stock name you want to buy (crack/jello/pinapple): ";
            cin >> stockName;
            cout << "Enter quantity to buy: ";
            cin >> quantity;

            // Find the stock based on the name
            for (int i = 0; i < SIZE; i++) {
                if (stocks[i].getName() == stockName) {
                    shop.buyStock(stocks[i], quantity, i);
                    break;
                }
            }
        }
        else if (choice == 2) {
            string stockName;
            int quantity;
            cout << "Enter the stock name you want to sell (crack/jello/pinapple): ";
            cin >> stockName;
            cout << "Enter quantity to sell: ";
            cin >> quantity;

            // Find the stock based on the name
            for (int i = 0; i < SIZE; i++) {
                if (stocks[i].getName() == stockName) {
                    shop.sellStock(stocks[i], quantity, i);
                    break;
                }
            }
        }
        else if (choice == 3) {
            cout << endl;
            cout << left << setw(20) << "Day" << ": " << dayCount << endl;
            cout << left << setw(20) << "Business Name" << ": " << shop.getName() << endl;
            cout << left << setw(20) << "Cash" << ": $" << shop.getCash() << endl;

            cout << "\n" << left << setw(20) << "Item" << setw(15) << "Inventory" << setw(15) << "Price" << setw(15) << "Holdings" << endl;
            cout << "---------------------------------------------------------------------" << endl;

            for (int i = 0; i < SIZE; i++) {
                cout << fixed << setprecision(2)
                    << left << setw(20) << shop.getItems(i)
                    << setw(15) << shop.getInventory(i)
                    << "$" << setw(14) << stocks[i].getPrice()
                    << "$" << setw(14) << (shop.getInventory(i) * stocks[i].getPrice())
                    << endl;
            }
        }
        else if (choice == 4) {
            dayCount++;
            for (int i = 0; i < SIZE; i++) {
                stocks[i].newPrice();
            }
            cout << "You log off for the day, hoping that tommorow brings better fortunes...\n";
        }
        else if (choice == 5) {
            cout << "Exiting the program. Thank you!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}