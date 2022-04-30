#include <iostream>
#include <string>
#include <vector>
#include <math.h> 
#include "Receipt.h"
#include "Products.h"
#include "Information.h"

using namespace std;

Receipt::Receipt(){
  
}

Receipt::Receipt(string mheader, vector<Products> mbuySummary, string mbarcode, string mfooter, double mTax){
  header = mheader;
  buySummary = mbuySummary;
  barcode = mbarcode;
  footer = mfooter;
  tax = mTax;
}

Receipt::~Receipt(){
  
}

// Getters
string Receipt::getHeader(){
  return header;
}

vector <Products> Receipt::getSummary(){
  return buySummary;
}

string Receipt::getBarcode(){
  return barcode;
}

string Receipt::getFooter(){
  return footer;
}

double Receipt::getTax(){
  return tax;
}

string Receipt::getPayment(){
  return payment;
}


// Setters
void Receipt::setHeader(string mheader){
  header = mheader;
}

void Receipt::setSummary(vector<Products> mmyProducts){
  buySummary = mmyProducts;
}

void Receipt::setBarcode(string mBarcode){
  barcode = "                            " + mBarcode;
}

void Receipt::setFooter(string mFooter){
  footer = "                          " + mFooter;
}

void Receipt::setTax(double mTax){
  tax = mTax;
}

void Receipt::setPayment(string mPayment){
  payment = mPayment;
}


string Receipt::Summary(){
  string str;
  double total;
  for (Products i : buySummary)
    {
      str+= "                 ";
      str += i.toString2();
      str += "\n";
      total += i.getPrice();
    }
  str += "                             ";
  str += "Subtotal: ";
  str += to_string(total);
  str += "\n";
  str += "                             ";
  str += "Tax: ";
  str += to_string(tax*100);
  str += "\n";
  str += "                             ";
  str += "Total: ";
  str += to_string(round(total + (total*tax)));
  str += "\n";
  str += "                          ";
  str += payment;
  return str;
}

//toString Function
string Receipt::toString(){
  return header + "\n" + "\n" + Summary() + "\n" + "\n" + barcode + "\n" + "\n" + footer;
}
