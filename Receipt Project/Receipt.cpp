#include <iostream>
#include <string>
#include <vector>
#include "Receipt.h"
#include "Products.h"


using namespace std;
Receipt::Receipt(){
  
}

Receipt::Receipt(string mheader, string mbuySummary, string mbarcode, string mfooter){
  header = mheader;
  buySummary = mbuySummary;
  barcode = mbarcode;
  footer = mfooter;
}

Receipt::~Receipt(){
  
}

// Getters
string Receipt::getHeader(){
  return header;
}

string Receipt::getSummary(){
  return buySummary;
}
string Receipt::getBarcode(){
  return barcode;
}

string Receipt::getFooter(){
  return footer;
}

// Setters
void Receipt::setHeader(string mheader){
  header = mheader;
}

void Receipt::setSummary(vector<Products> myProducts){
  for (Products i : myProducts)
    {
      cout << i.toString() << endl;
    }
}

void Receipt::setBarcode(string mBarcode){
  barcode = mBarcode;
}

void Receipt::setFooter(string mFooter){
  footer = mFooter;
}

//toString Function
string Receipt::toString(){
  return header + "\n" + "\n" + buySummary + "\n" + "\n" + barcode + "\n" + "\n" + footer;
}
