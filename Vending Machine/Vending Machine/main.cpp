#include <iostream>
#include <fstream>
#include <string>
#include "header.h"

using namespace std;

// Function which returns a boolean value representing whether the specified item that is passed in is in stock.
bool checkStock(const Product& product) {
    return (product.stock > 0);
}

void displayMenu(const Product& product) {
    cout << "|| " << product.name << " | Stock: " << product.stock << " || " << endl;
}

// Function which is used when user selects an item to purchase
void purchaseItem(Product& item, int& currentBalance) {
    int itemCost;

    // If item is in stock and the user has enough balance, the users balance and the items stock is updated then the item is 'dispensed'
    if (checkStock(item) && currentBalance >= item.cost) {

        itemCost = item.cost;
        item.stock--;
        currentBalance -= itemCost;
        
        cout << "Purchase successful. Remaining balance: " << currentBalance << endl;
    } else if (!checkStock(item)) {
        cout << "Sorry, " << item.name << " is out of stock." << endl;
    } else {
        cout << "Insufficient balance. Please top up your account." << endl;
    }
}

// Main menu for the purchasing of food.
void foodMenu(Product& food1, Product& food2, Product& food3, Product& food4, Product& food5, int& currentBalance) {
    int menuChoice;
    char continueShopping;

    // Food menu is printed with the displayMenu function being used to print out the item name and stock for each item after its corresponding number
    do {
        cout << "Food Menu:" << endl;
        cout << "1. ";
        displayMenu(food1);
        cout << "2. ";
        displayMenu(food2);
        cout << "3. ";
        displayMenu(food3);
        cout << "4. ";
        displayMenu(food4);
        cout << "5. ";
        displayMenu(food5);
        cout << "9. Exit" << endl;

        cin >> menuChoice;

        // Depending on what item the user selects, the purchaseItem function is run with the item of choice and the users current balance
        switch (menuChoice) {
        case 1:
            purchaseItem(food1, currentBalance);
            break;
        case 2:
            purchaseItem(food2, currentBalance);
            break;
        case 3:
            purchaseItem(food3, currentBalance);
            break;
        case 4:
            purchaseItem(food4, currentBalance);
            break;
        case 5:
            purchaseItem(food5, currentBalance);
            break;
        case 9:
            cout << "Exiting food menu." << endl;
            return;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }

        // through the use of a while loop,if  the users balance is 0 or above, the user will be asked if they wish to continue shopping
        if (currentBalance >= 0) {
            cout << "Do you want to continue shopping? (y/n): ";
            cin >> continueShopping;
        } else {
            cout << "Insufficient balance. Exiting." << endl;
            break;
        }

    } while (continueShopping == 'y' || continueShopping == 'Y');
}

void drinkMenu(Product& drink1, Product& drink2, Product& drink3, Product& drink4, Product& drink5, int& currentBalance) {
    int menuChoice;
    char continueShopping;

    //Just like the food menu, the drinks menu is printed with the displayMenu function being used to print out the item name and stock for each item after its corresponding number
    do {
        cout << "Drink Menu:" << endl;
        cout << "1. ";
        displayMenu(drink1);
        cout << "2. ";
        displayMenu(drink2);
        cout << "3. ";
        displayMenu(drink3);
        cout << "4. ";
        displayMenu(drink4);
        cout << "5. ";
        displayMenu(drink5);
        cout << "9. Exit" << endl;

        cin >> menuChoice;

        switch (menuChoice) { //Switch statement depending on which item the user selects to purchase
        case 1:
            purchaseItem(drink1, currentBalance);
            break;
        case 2:
            purchaseItem(drink2, currentBalance);
            break;
        case 3:
            purchaseItem(drink3, currentBalance);
            break;
        case 4:
            purchaseItem(drink4, currentBalance);
            break;
        case 5:
            purchaseItem(drink5, currentBalance);
            break;
        case 9:
            cout << "Exiting drink menu." << endl;
            return;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }

        if (currentBalance >= 0) {
            cout << "Do you want to continue shopping? (y/n): ";
            cin >> continueShopping;
        } else {
            cout << "Insufficient balance. Exiting." << endl;
            break;
        }

    } while (continueShopping == 'y' || continueShopping == 'Y');
}

// Simple function for topping up balance by taking the balances current value and adding on the entered amount of new balance
int enterMoney(int currentBalance) {
    int newMoney;

    cout << "How much money would you like to enter? Enter the amount in pence: ";
    cin >> newMoney;

    currentBalance = newMoney + currentBalance;
    return currentBalance;
}

//Function for printing main menu of program, uses file handling to retrieve the vending machine graphic from mainMenu.txt
void mainMenu(Product &food1, Product &food2, Product &food3, Product &food4, Product &food5, Product &drink1, Product &drink2, Product &drink3, Product &drink4, Product &drink5, int &currentBalance){
    
    int menuChoice;
    ifstream inputFile("mainMenu.txt");
    string data;
    
    if (inputFile.is_open()) {
        while (getline(inputFile, data)) {
            cout << data << "\n";
        }
        
        inputFile.close();
    } else {
        cout << "File cannot be accessed. Terminating program" << endl;
    }
    
    cout << "1. Purchase food" << endl;
    cout << "2. Purchase drinks" << endl;
    cout << "3. Top-up Money" << endl;
    cin >> menuChoice;
    
    switch (menuChoice) { //Switch statement for different user inputs
        case 1:
            foodMenu(food1, food2, food3, food4, food5, currentBalance);
            break;
        case 2:
            drinkMenu(drink1, drink2, drink3, drink4, drink5, currentBalance);
            break;
        case 3:
            currentBalance = enterMoney(currentBalance);
            cout << "New balance: " << currentBalance << endl;
            break;
        default:
            cout << "Invalid choice. Exiting." << endl;
    }
}

// Objects are created for each of the food and drink items in the vending machine, an initial user balance is set, the menu function is ran with all of the new objects being passed in
 int main() {
     Product drink1("Coke", 200, 5);
     Product drink2("Water", 150, 5);
     Product drink3("Fanta", 150, 5);
     Product drink4("Monster", 150, 5);
     Product drink5("Oasis", 150, 5);
     Product food1("Sandwich", 300, 3);
     Product food2("Crisps", 150, 5);
     Product food3("Mints", 150, 5);
     Product food4("Sweets", 150, 5);
     Product food5("Chocolate", 150, 5);

     int currentBalance = 500;
 
     mainMenu(food1, food2, food3, food4, food5, drink1, drink2, drink3, drink4, drink5, currentBalance);
     
  }
