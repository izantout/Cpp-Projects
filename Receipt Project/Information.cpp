// Including Libraries
#include <iostream>
#include <fstream>

// Including Header Files
#include "Information.h"

using namespace std;

// Defualt Constructor
Information::Information()
{
  
}

// Overloaded Contructor
Information::Information(string mAddress, string mLogo, string mNumber, string mManagerName, string mDate, string mTime, string mCoupons, double mTax)
{
  Address = mAddress;
  Logo = mLogo;
  Number = mNumber;
  Name = mManagerName;
  Date = mDate;
  Time = mTime;
  Coupons = mCoupons;
  Tax = mTax/100;
}

// Destructor
Information::~Information()
{
  
}

// Getters
string Information::getAddress()
{
  return Address;
}

string Information::getLogo()
{
  return Logo;
}

string Information::getNumber()
{
  return Number;
}

string Information::getName()
{
  return Name;
}

string Information::getdate()
{
  return Date;
}

string Information::getTime()
{
  return Time;
}

string Information::getcoupons()
{
  return Coupons;
}

double Information::getTax()
{
  return Tax;
}


// Setters
void Information::setAddress(string mAddress)
{
  Address = mAddress;
}

void Information::setLogo(string mLogo)
{
  Logo = mLogo;
}

void Information::setNumber(string mNumber)
{
  Number = mNumber;
}

void Information::setManagerName(string mName)
{
  Name = mName;
}

void Information::setDate(std::string mDate)
{
  Date = mDate;
}

void Information::setTime(string mTime)
{
  Time = mTime;
}

void Information::setcoupons(string mCoupons)
{
  Coupons = mCoupons;
}

void Information::setTax(double mTax)
{
  Tax = mTax;
}

//toString functions
string Information::toStringTop(){
  return "                                  " + Logo + "\n" + "                             " + Number + "\n" + "                             " + Name + "\n" + "                             " + Address + "\n";
}

string Information::toStringMiddle(){
  return to_string(Tax*100);
}

string Information::toStringBottom(){
  return Coupons + "\n" + "Thank You for Shopping With Us! \n" + Date + "    " + Time + "\n" + "***** CUSTOMER COPY *****";
}
