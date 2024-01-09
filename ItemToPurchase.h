#ifndef ItemToPurchase_h
#define ItemToPurchase_h

#include <iostream>
#include <string>

using namespace std;

class ItemToPurchase {
    public: 

        ItemToPurchase();
        ItemToPurchase(string inName, string inDescrip, double inPrice, int inQuantity);

        void setName(string inName);
        string name() const;
        void setPrice(double inPrice);
        double price() const;
        void setQuantity(int inQuantity);
        int quantity() const;

        void setDescription(string inDescription);
        string description(); 
        void printItemCost();
        void printItemDescription();


    private:

        string _name;
        double _price;
        int _quantity;
        string _description;


};

#endif