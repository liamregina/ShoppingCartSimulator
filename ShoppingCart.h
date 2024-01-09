#ifndef ShoppingCart_h
#define ShoppingCart_h

#include <iostream>
#include <string>
#include <vector>
#include "ItemToPurchase.h"

using namespace std;

class ShoppingCart {
    public:
        ShoppingCart();
        ShoppingCart(string name, string date);

        string customerName();
        string date();
        void addItem(ItemToPurchase item);
        void removeItem(string itemName);
        void modifyItem(ItemToPurchase item);
        int numItemsInCart();
        double costOfCart();
        void printTotal();
        void printDescriptions();

    private:
        string _customerName;
        string _currentDate;
        vector<ItemToPurchase> _cartItems; 



};

#endif
