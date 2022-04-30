#include <iostream>
#include <string>
#include "Barcode.h"

using namespace std;

// Default constructor
Barcode::Barcode(){
  
}

//Overloaded Constructor
Barcode::Barcode(string mdate, string mtime, string memployeeName, string mcashierNumber){
  string Barcode = "||||||||||||||||||||||||";
  srand(time(0));
  for(int i=0; i<5; i++)
  {
    int random = (rand() % 10);
    Barcode.replace(random,1," ");
  }
  barcode = Barcode;
  date = mdate;
  ptime = mtime;
  employeeName = memployeeName;
  cashierNumber = mcashierNumber;
}

// Desturtcor
Barcode::~Barcode(){
  
}

// Getters
string Barcode::getBarcode(){
  return barcode;
}

string Barcode::getDate(){
  return date;
}

string Barcode::getTime(){
  return ptime;
}

string Barcode::getName(){
  return employeeName;
}

string Barcode::getNumber(){
  return cashierNumber;
}

// Setters
void Barcode::setBarcode(){
  string Barcode = "||||||||||||||||||||||||";
  srand(time(0));
  for(int i=0; i<5; i++)
  {
    int random = (rand() % 10);
    Barcode.replace(random,1," ");
  }
  barcode = Barcode;
}

void Barcode::setDate(string mdate){
 date = mdate; 
}

void Barcode::setTime(string mtime){
  ptime = mtime;
}

void Barcode::setName(string mname){
  employeeName = mname;
}

void Barcode::setNumber(string mnumber){
  cashierNumber = mnumber;
}
