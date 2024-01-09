#include <iostream>
#include <string>
#include <vector>

#include "ShoppingCart.h"

using namespace std;

ShoppingCart :: ShoppingCart() {
    _customerName = "none";
    _currentDate = "January 1, 2016";
}

ShoppingCart :: ShoppingCart(string name, string date) {
    _customerName = name;
    _currentDate = date;
}

string ShoppingCart :: customerName() {return _customerName;}

string ShoppingCart :: date() {return _currentDate;}

void ShoppingCart :: addItem(ItemToPurchase item) {
    _cartItems.push_back(item);
}

void ShoppingCart :: removeItem(string itemName) {
    unsigned int i;
    bool notInList = false;
    for (i = 0; i < _cartItems.size(); ++i) {
        if (itemName == _cartItems.at(i).name()) {
            _cartItems.erase(_cartItems.begin() + i);
            return;
        }
    }
        
    if (i == _cartItems.size()) {
            notInList = true;
    }


    if (notInList) {
            cout << "Item not found in cart. Nothing removed." << endl;
        }
}

void ShoppingCart :: modifyItem(ItemToPurchase item) {

    unsigned int i;
    int newQuantity;

    cout << "Enter the new quantity: " << endl;
    cin >> newQuantity;
    cin.ignore();


    for (i = 0; i < _cartItems.size(); ++i) {
        if (_cartItems.at(i).name() == item.name()) {
            _cartItems.at(i).setQuantity(newQuantity);
            return; 
        }
    }

    if (i == _cartItems.size()) {
            cout << "Item not found in cart. Nothing modified." << endl;
    }
}

int ShoppingCart :: numItemsInCart() {
    int count = 0;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        count += _cartItems.at(i).quantity();
    }
    return count;
}

double ShoppingCart :: costOfCart() {
    double cost = 0;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        cost += _cartItems.at(i).quantity() * _cartItems.at(i).price();
    }
    return cost;
}

void ShoppingCart :: printTotal() {


    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << "Number of Items: " << numItemsInCart() << endl << endl;
    
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        _cartItems.at(i).printItemCost();
    }

    if (_cartItems.size() == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }

    cout << endl;

    cout << "Total: $" << costOfCart() << endl;
}



void ShoppingCart :: printDescriptions() {

    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl << endl;

    cout << "Item Descriptions" << endl;

    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        _cartItems.at(i).printItemDescription();
    }
}

