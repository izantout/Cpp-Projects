#include <iostream>
#include <string>
#include <vector>
#include "Receipt.h"
#include "Products.h"


using namespace std;
Receipt::Receipt(){
  
}

Receipt::Receipt(string mheader, vector<Products> mbuySummary, string mbarcode, string mfooter){
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

vector <Products> Receipt::getSummary(){
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

void Receipt::setSummary(vector<Products> mmyProducts){
  buySummary = mmyProducts;
}

void Receipt::setBarcode(string mBarcode){
  barcode = "                            " + mBarcode;
}

void Receipt::setFooter(string mFooter){
  footer = mFooter;
}

string Receipt::trial(){
  string str;
  for (Products i : buySummary)
    {
      str+= "                 ";
      str += i.toString2();
      str += "\n";
    }
  return str;
}

//toString Function
string Receipt::toString(){
  return header + "\n" + "\n" + trial() + "\n" + "\n" + barcode + "\n" + "\n" + footer;
}
