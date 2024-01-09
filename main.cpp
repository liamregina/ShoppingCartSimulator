#include <iostream>
#include "ShoppingCart.h"

using namespace std;

void printMenu(ShoppingCart & cart) {
    char menuChar;
    string itemName;
    string itemDescrip;
    double itemPrice;
    int itemQuantity;

    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl << endl;

    cout << "Choose an option: ";
    cin >> menuChar;
    cout << endl;

    while (menuChar != 'a' && menuChar != 'd' && menuChar != 'c' && menuChar != 'i' && menuChar != 'o' && menuChar != 'q') {
        cout << "Choose an option: ";
        cin >> menuChar; 
        cout << endl;
    }
    if (menuChar == 'q') {
        exit(0);
    }
    else if (menuChar == 'a') {
        cout << endl;
        cout << "ADD ITEM TO CART" << endl;
        cout << "Enter the item name: " << endl;
        cin.ignore();
        getline(cin, itemName);
        cout << "Enter the item description: " << endl;
        getline(cin, itemDescrip);
        cout << "Enter the item price: " << endl;
        cin >> itemPrice;
        cout << "Enter the item quantity: " << endl;
        cin >> itemQuantity;

        ItemToPurchase itemToAdd;

        itemToAdd.setName(itemName);
        itemToAdd.setDescription(itemDescrip);
        itemToAdd.setPrice(itemPrice);
        itemToAdd.setQuantity(itemQuantity);
        cart.addItem(itemToAdd);
    }
    else if (menuChar == 'd') {
        cout << endl;
        cout << "REMOVE ITEM FROM CART" << endl;
        cout << "Enter name of item to remove: " << endl;
        cin.ignore();
        getline(cin, itemName);
        cart.removeItem(itemName);
    }
    else if (menuChar == 'c') {
        cout << endl;
        cout << "CHANGE ITEM QUANTITY" << endl;
        cout << "Enter the item name: " << endl;
        cin.ignore();
        getline(cin, itemName);
        
        ItemToPurchase tmp;
        tmp.setName(itemName);

        cart.modifyItem(tmp);
    }
    else if (menuChar == 'i' ) {
        cout << endl;
        cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
        cart.printDescriptions();
        
    }
    else if (menuChar == 'o') {
        cout << endl;
        cout << "OUTPUT SHOPPING CART" << endl;
        cart.printTotal();
    }
    
}

int main() {
    string name;
    string date;

    cout << "Enter customer's name: ";
    getline(cin, name);
    cout << endl;
    cout << "Enter today's date: ";
    getline(cin, date);
    cout << endl << endl;
    cout << "Customer name: " << name << endl;
    cout << "Today's date: " << date << endl << endl;

    ShoppingCart userCart(name, date);

    while (true) {
        printMenu(userCart);
        cout << endl;
    }

    return 0;
}