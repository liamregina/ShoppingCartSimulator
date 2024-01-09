#include <iostream>
#include <string>

#include "ItemToPurchase.h"

using namespace std;

ItemToPurchase :: ItemToPurchase() {
    _name = "none";
    _price = 0;
    _quantity = 0;
    _description = "none";
}

ItemToPurchase :: ItemToPurchase(string inName, string inDescrip, double inPrice, int inQuantity) {
    _name = inName;
    _description = inDescrip;
    _price = inPrice;
    _quantity = inQuantity;
}

void ItemToPurchase :: setName(string inName) {_name = inName;}

string ItemToPurchase :: name() const {return _name;}

void ItemToPurchase :: setPrice(double inPrice) {_price = inPrice;}

double ItemToPurchase :: price() const {return _price;}

void ItemToPurchase :: setQuantity(int inQuantity) {_quantity = inQuantity;}

int ItemToPurchase :: quantity() const {return _quantity;}

void ItemToPurchase :: setDescription(string inDescription) {_description = inDescription;}

string ItemToPurchase :: description() {return _description;}

void ItemToPurchase :: printItemCost() {
    cout << _name << " " << _quantity << " @ $" << _price << " = $" << _quantity * _price << endl;
}

void ItemToPurchase :: printItemDescription() {
    cout << _name << ": " << _description << endl;
}

