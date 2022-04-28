#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

// Default Constructor
Card::Card(){
  
}

// Overloaded Contrustor
Card::Card(std::string mNumber, std::string mPin){
  cardNumber = mNumber;
  cardPin = mPin;
}

//Destructor
Card::~Card(){
  
}

// Getters
string Card::getNumber(){
  return cardNumber;
}

string Card::getPin(){
  return cardPin;
}

string Card::getType(){
  return cardType;
}

// Setters
void Card::setNumber(string mNumber){
  cardNumber = mNumber;
}

void Card::setPin(string mPin){
  cardPin = mPin;
}

void Card::setType(string mType){
  cardType = mType;
}

// toString function
string Card::toString(){
  int numberLength = cardNumber.length();
  string coveredNumber = "";
  for (int i=0; i<numberLength-4; i++)
    {
      coveredNumber += "*";
    }
  for (int i=(numberLength-4); i<numberLength; i++)
    {
      coveredNumber+= cardNumber[i];
    }
  return coveredNumber;
}
