// ****** Libraries ******
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <math.h> 
// ***********************

// ***** Class Files *****
#include "Products.h"
#include "Information.h"
#include "Card.h"
#include "Receipt.h"
#include "Barcode.h"
// ***********************

using namespace std;

// ***** Prototypes ***** 
void printVector(vector<Products> myInventory);
void printVector(vector<string> myVec);
string toUpper(string value);
void itemScan(vector<string>& items);
void Payments(Information& myInfo, double& total, Receipt& myReceipt, vector<string>& items);
void InventoryUpdate(vector<string>& items, vector<Products>& myInventory, double& total);
void buySummary(vector<string>& items, vector<Products>& myInventory, vector<Products>& myProducts);
float rounding(float value, float r = 2);

// ***** Main Function *****
int main() 
{
  // ***** Needed for final submission *****
  ofstream outfile("Receipt.txt");
  
  // *****PRODUCTS*****
  Products Bananas("Banana", "023442", 10, 3.99);
  Products Milk("Milk", "023443", 10, 10.99);
  Products Shoes("Shoes", "023444", 10, 34.99);
  Products Water("Water", "023445", 10, 1.99);
  Products Pepsi("Pepsi", "023446", 50, 1.99);
  Products Laptop("HPGL", "023447", 4, 1799.99);
  // ******************
  
  Information myInfo("888 WALL STORE ST \n                             WALL ST CITY, LA 88888", "WALMART", "(888) 888 - 8888", "MANAGER TOD LINGA", "10/17/2022", "16:12", "$10 off a purchase of $50 or more!", 7.89);
  Receipt myReceipt;
  Barcode myBarcode(myInfo.getdate(), myInfo.getTime(), "Issam Zantout", "Cashier Number 2");
  vector<Products> myInventory;
  vector<string> items;
  vector<Products> finalProducts;
  double total=0;

  // *******Receipt Creation*******
  myReceipt.setHeader(myInfo.toStringTop());
  myReceipt.setBarcode(myBarcode.getBarcode());
  myReceipt.setFooter(myInfo.toStringBottom());
  // ******************************
  
  // *******Products Vector Creation*******
  myInventory.push_back(Bananas);
  myInventory.push_back(Milk);
  myInventory.push_back(Shoes);
  myInventory.push_back(Water);
  myInventory.push_back(Pepsi);
  myInventory.push_back(Laptop);
  // **************************************

  // *******Main Code Execution Area*******
  itemScan(items);
  InventoryUpdate(items, myInventory, total);
  Payments(myInfo, total, myReceipt, items);
  buySummary(items, myInventory, finalProducts);
  myReceipt.setTax(myInfo.getTax());
  myReceipt.setSummary(finalProducts);

  outfile << myReceipt.toString();
  // ****************************************
}
// *************************

// ******* Functions *******
void Payments(Information& myInfo, double& total, Receipt& myReceipt, vector<string>& items)
{
  
  string paySelection = "", cardNumber = "", cardType = "", cardPin = "", cardBrand = "";
  bool flag = true;
  cout << "Would you like to pay with cash or card? ";
  cin >> paySelection;
  flag = true;
  while(flag)
  {
    if (toUpper(paySelection) == "CARD")
    {
      cout << "Please Slid or Enter Your Card: ";
      cin >> cardNumber;
      cout << "Is your card Debit or Credit: ";
      cin >> cardType;
      cout << "What is your card type(e.g. Visa, MasterCard...): ";
      cin >> cardBrand;
      if (toUpper(cardType) == "DEBIT")
      {
        cout << "Please enter the Pin: ";
        cin >> cardPin;
        cout << "SLIDE" << endl << "ACCEPTED" << endl << "Printing Receipt... " << endl;
        flag = false;
        Card myCard(cardNumber, cardPin, cardBrand);
        string str = "DEBIT ACCEPTED \n                          Change: 0.00";
        str += "\n                 ACCOUNT:  ";
        str += myCard.toString();
        str += "\n                          # ITEMS BOUGHT: ";
        str += to_string(items.size());
        myReceipt.setPayment(str);
      }
      else if(toUpper(cardType) == "CREDIT")
      {
        cout << "SLIDE" << endl << "ACCEPTED" << endl;
        cout << "Printing Receipt... " << endl;
        flag = false;
        Card myCard(cardNumber, cardBrand);
        string str = "CREDIT ACCEPTED \n                          Change: 0.00";
        str += "\n                 ACCOUNT:  ";
        str += myCard.toString();
        str += "\n                          # ITEMS BOUGHT: ";
        str += to_string(items.size());
        myReceipt.setPayment(str);
      }
      else
      {
        cout << "Invalid selection, Please try again: " << endl;
      }
    }
    else if(toUpper(paySelection) == "CASH")
    {
      double cash;
      cout << "Subtotal: " << total << endl;
      cout << "Tax: " << rounding(myInfo.getTax()*total) << endl;
      total = rounding(total + (total * myInfo.getTax()));
      cout << "Balance due: " << total << endl;
      cout << "Please insert cash: ";
      cin >> cash;
      if (cash > total)
      {
        cout << "Your change is " << rounding(cash-total) << endl << "Printing Receipt..." << endl;
        string str = "CASH \n                          Change: ";
        str += to_string(cash-total);
        str += "\n                          # ITEMS BOUGHT: ";
        str += to_string(items.size());
        myReceipt.setPayment(str);
        flag = false;
      }
      else if(cash == total)
      {
        cout << "Printing Receipt..." << endl;
        string str = "CASH \n                          Change: 0.00";
        str += "\n                          # ITEMS BOUGHT: ";
        str += to_string(items.size());
        myReceipt.setPayment(str);
        flag = false;
      }
      else
      {
        float change;
        while(cash<total)
        {
          total = rounding(total-cash);
          cout << "You still owe: " << total << endl;
          cout << "Please insert cash: ";
          cin >> cash;
        }
        cout << "Printing Receipt..." << endl;
        if (cash > total)
        {
          change =  rounding(cash-total);
        }
        else
        {
          change = 0;
        }
        string str = "CASH \n                          Change: ";
        str += to_string(change);
        str += "\n                          # ITEMS BOUGHT: ";
        str += to_string(items.size());
        myReceipt.setPayment(str);
        flag = false;
      }
    }
    else
    {
      cout << "Invalid selection, Please try again: ";
      cin >> paySelection;
    }
  }
}
  
void itemScan(vector<string>& items)
{
  bool flag = true;
  string selection = "";
  while(flag)
  {
    cout << "Please scan your item (Press F to finish): ";
    cin >> selection;
    if(toUpper(selection) == "F")
    {
      flag = false;
    }
    else
    {
      items.push_back(selection);
    }
  }
}

void printVector(vector<Products> myInventory)
{
  for (int i=0; i<myInventory.size(); i++)
  {
    cout << myInventory[i].toString() << endl << endl;
  }
}

string toUpper(string value)
{
  for (int i=0;i<value.length(); i++)
    {
      value[i] = toupper(value[i]);
    }
  return value;
}

void printVector(vector<string> myVec)
{
  for(string val : myVec)
    {
      cout << val << " ";
    }
  cout << endl;
}

void InventoryUpdate(vector<string>& items, vector<Products>& myInventory, double& total)
{
  for (int i=0; i<items.size(); i++)
  {
    for (int j=0; j<myInventory.size(); j++)
    {
      if(items[i] == myInventory[j].getSNumber())
      {
        myInventory[j].setQuantity(myInventory[j].getQuantity()-1);
        total += myInventory[j].getPrice();
      }
    }
  }
}

void buySummary(vector<string>& items, vector<Products>& myInventory, vector<Products>& myProducts)
{
  for (int i=0; i<items.size(); i++)
  {
    for (int j=0; j<myInventory.size(); j++)
    {
      if(items[i] == myInventory[j].getSNumber())
      {
        myProducts.push_back(Products(myInventory[j].getName(), myInventory[j].getSNumber(), myInventory[j].getPrice()));
      }
    }
  }
}

float rounding(float value, float r)
{
  float pow_10 = pow(10.0f, r);
  return round(value * pow_10) / pow_10;
}
// *************************
