// ***** Libraries *****
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

// ***** Class Files *****
#include "Products.h"
#include "Information.h"
#include "Card.h"
#include "Receipt.h"

using namespace std;

// ***** Prototypes ***** 
void printVector(vector<Products> myInventory);
void printVector(vector<string> myVec);
string Barcode();
string toUpper(string value);
void itemScan(vector<string>& items);
void Payments(Information myInfo, double& total);
void InventoryUpdate(vector<string>& items, vector<Products>& myInventory, double& total);
string buySummary(vector<string>& items, vector<Products>& myInventory);

// ***** Main Function *****
int main() 
{
  // ***** Needed for final submission *****
  Products Milk("Milk", "023443", 10, 12.99);
  Products Water("Water", "023444", 10, 1.99);
  vector<Products> myInventory;
  vector<string> items;
  Information myInfo("888 WALL STORE ST \n WALL ST CITY, LA 88888", "WALMART", "(888) 888 - 8888", "MANAGER TOD LINGA", "10/17/2022", "16:12", "Save this receipt and get $10 off your next purchase of $50 or more!", 7.89);
  double total=0;
  Receipt myReceipt;
  myReceipt.setHeader(myInfo.toStringTop());
  myReceipt.setBarcode(Barcode());
  myReceipt.setFooter(myInfo.toStringBottom());
  // *******Card function testing area*******
  // Card myCard("0987654321324", "9283");
  // cout << myCard.toString() << endl;
  // ****************************************

  // *******Information function testing area*******

  // cout << "TOP: \n" << myInfo.toStringTop() << endl;
  // cout << "MID: \n" << myInfo.toStringMiddle() << endl;
  // cout << "BOTTOM: \n" << myInfo.toStringBottom() << endl;
  // ***********************************************

  // *******Products function testing area*******
  myInventory.push_back(Milk);
  myInventory.push_back(Water);
  // *******************************************

  // *******Main Code Execution Area*******
  itemScan(items);
  InventoryUpdate(items, myInventory, total);
  Payments(myInfo, total);
  // ****************************************
}

// ***** Functions *****
void Payments(Information myInfo, double& total)
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
      }
      else if(toUpper(cardType) == "CREDIT")
      {
        cout << "SLIDE" << endl << "ACCEPTED" << endl;
        cout << "Printing Receipt... " << endl;
        flag = false;
        Card myCard(cardNumber, "0000", cardBrand);
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
      cout << "Tax: " << myInfo.getTax()*total << endl;
      total = total + (total * myInfo.getTax());
      cout << "Balance due: " << total << endl;
      cout << "Please insert cash: ";
      cin >> cash;
      if (cash > total)
      {
        cout << "Your change is " << cash-total << endl << "Printing Receipt..." << endl;
        flag = false;
      }
      else if(cash == total)
      {
        cout << "Printing Receipt..." << endl;
        flag = false;
      }
      else
      {
        while(cash<total)
        {
          total = total-cash;
          cout << "You still owe: " << total << endl;
          cout << "Please insert cash: ";
          cin >> cash;
        }
        cout << "Printing Receipt..." << endl;
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

string Barcode()
{
  string Barcode = "|||||||||";
  srand(time(0));
  for(int i=0; i<3; i++)
  {
    int random = (rand() % 10);
    Barcode.replace(random,1," ");
  }
  return Barcode;
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

string buySummary(vector<string>& items, vector<Products>& myInventory){
  string summary = "";
  for (int i=0; i<items.size(); i++)
  {
    for (int j=0; j<myInventory.size(); j++)
    {
      if(items[i] == myInventory[j].getSNumber())
      {
        final = final + myInventory[j].getName() + "   " + myInventory[j].getSNumber() + "     " + to_string(myInventory[j].getPrice());
      }
    }
  }
  return summary;
}
