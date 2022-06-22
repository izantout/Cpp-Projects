#ifndef SHELVES_H
#define SHELVES_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include "Books.h"

using namespace std;

class Shelves{
  private:
    std::vector<Books> myBooks;
    std::vector<std::string> myBookNames;

  public:

    Shelves(){
      
    }

    Shelves(vector<Books> mmyBooks){
      myBooks = mmyBooks;
    }

    ~Shelves(){
      
    }
      
    void getBooks(){
      orderBooks(myBooks);
    }

    void setBooks(vector<Books> mmyBooks){
      myBooks = mmyBooks;
    }

    void orderBooks(vector<Books> myBooks){
      for(Books i : myBooks){
        myBookNames.push_back(toUpper(i.getName()));
      }
      sort(myBookNames.begin(), myBookNames.end());
      for (string i : myBookNames){
        cout << i << endl;
      }
    }

    void searchfor(){
      int copyNumber;
      string bookName;
      string checkoutChoice;
      bool flag;
      cout << "Please enter the book name you want to search for: ";
      getline(cin, bookName);
      for(Books i : myBooks){
        flag = comparing(i.getName(), bookName);
        if(flag){
          cout << "We have " << i.getInventory() << " copies in the library and it costs $" << i.getPrice() << "." << endl << "Would you like to buy this book? (yes or no) ";
          getline(cin, checkoutChoice);
          if(comparing(toUpper(checkoutChoice), "YES")){
            cout << "How many copies would you like to buy? ";
            cin >> copyNumber;
            if(copyNumber<= i.getInventory()){
              checkoutBook(i.getName(), myBooks, copyNumber);
              cout << "Enjoy your book and come again" << endl;
              break;
            }
            else{
              cout << "We dont have this many books in the library." << endl;
              break;
            }
          }
          else if(comparing(toUpper(checkoutChoice), "NO")){
            cout << "Ok, thank you... See you next time" << endl;
            break;
          }
          else{
            cout << "Invalid input... Try again" << endl;
            break;
          }
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

    void checkoutBook(string bookName, vector<Books> myBooks, int copyNumber){
      for(Books i : myBooks){
        if(comparing(i.getName(),bookName)){
          cout << "Your total is: $" << i.getPrice()*copyNumber << endl;
          i.setInventory(i.getInventory()-copyNumber);
          cout << "The remaining number of copies for " << i.getName() << " is: " << i.getInventory() << endl;
        }
      }
    }

};

#endif
