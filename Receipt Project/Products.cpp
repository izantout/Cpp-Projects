#include <iostream>
#include <string>
#include "Products.h"

using namespace std;

// Defualt Constructor
Products::Products(){
  
}

// Overloaded Constructor
Products::Products(string mName, string SNumber, int mQuantity, double mPrice){
  name = mName;
  SerialNumber = SNumber;
  quantity = mQuantity;
  price = mPrice;
}

Products::Products(string mName, string SNumber, double mPrice){
  name = mName;
  SerialNumber = SNumber;
  price = mPrice;
}

// Getters
string Products::getName(){
  return name;
}

string Products::getSNumber(){
  return SerialNumber;
}

int Products::getQuantity(){
  return quantity;
}

double Products::getPrice(){
  return price;
}

// Setters
void Products::setName(string mName){
  name = mName;
}

void Products::setSNumber(string mNumber){
  SerialNumber = mNumber;
}

void Products::setQuantity(int mQuantity){
  quantity = mQuantity;
}

void Products::setPrice(double mPrice){
  price = mPrice;
}

// ToString
string Products::toString(){
  return "Product: " + name + "\n" + 
         "Serial Number: " + SerialNumber + "\n" + 
         "Quantity: " + to_string(quantity) + "\n" + 
         "Price: " +  to_string(price);
}
