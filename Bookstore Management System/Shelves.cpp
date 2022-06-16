#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <ctype.h>
#include "Shelves.h"

using namespace std;

void getBooks();
void setBooks();
void checkoutBook();
void orderBooks(vector<Books> myBooks);
bool comparing(string str1, string str2);
string toUpper(string mystring);


Shelves::Shelves(){
  
}

Shelves::Shelves(vector<Books> mmyBooks){
  myBooks = mmyBooks;
}

Shelves::~Shelves(){
  
}
  
void Shelves::getBooks(){
  orderBooks(myBooks);
}

void Shelves::setBooks(vector<Books> mmyBooks){
  myBooks = mmyBooks;
}

void Shelves::orderBooks(vector<Books> myBooks){
  for(Books i : myBooks){
    myBookNames.push_back(toUpper(i.getName()));
  }
  sort(myBookNames.begin(), myBookNames.end());
  for (string i : myBookNames){
    cout << i << endl;
  }
}

void Shelves::searchfor(){
  string bookName;
  bool flag = true;
  cout << "Please enter the book name you want to search for: ";
  getline(cin, bookName);
  for(int i=0;i<myBookNames.size();i++){
    flag = comparing(myBookNames[i], bookName);
    if(flag){
      cout << "We have the book in the library" << endl;
      break;
    }
  }
  if(!flag){
    cout << "We dont have the book in the library" << endl;
  }
}

string toUpper(string mystring){
  string final;
  for (char i : mystring){
    final += toupper(i);
  }
  return final;
}

bool comparing(string str1, string str2){
  int maxlength;
  bool flag;
  if(str1.length() > str2.length()){
    maxlength = str1.length();
  }
  else{
    maxlength = str2.length();
  }
  for(int i=0;i<maxlength;i++){
    if (toupper(str1[i]) != toupper(str2[i])){
      flag = false;
      break;
    }
    else{
      flag = true;
    }
  }
  return flag;
}

void Shelves::checkoutBook(){
  string bookName;
  cout << "Please enter the name of the book you want to checkout: ";
  getline(cin, bookName);
  for(int i=0; i<myBooks.size();i++){
    if(comparing(toUpper(myBooks[i].getName()), bookName)){
      myBooks.erase(myBooks[i]);
    }
  }
}
