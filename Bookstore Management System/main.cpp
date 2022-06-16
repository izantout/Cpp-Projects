#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Books.h"
#include "Shelves.h"

using namespace std;

int main() {
// ----- 1. Variable Decleration -----
// ----- Outfile -----
  ofstream outfile("Book.txt");

// ----- Book Section -----
  Books myBooks;
  Books Book1("Harry Potter and the prisoners of azkaban");
  Books Book2("Harry Potter and the goblet of fire");
  Books Book3("Harry Potter and the chamber of secrets");
  Books Book4("Harry Potter and the philosopher's stone");
  
  vector<Books> BooksinLibrary;
  BooksinLibrary.push_back(Book1);
  BooksinLibrary.push_back(Book2);
  BooksinLibrary.push_back(Book3);
  BooksinLibrary.push_back(Book4);
  
// ----- Shelves Section -----
  Shelves myShelf(BooksinLibrary);

// ----- Content Section -----
string myString = "Whatever paragraph a aperson wants to set as content goes here";
  
// ----- 2. Function Calling -----
  // myBooks.setContent(myString); // Sets Content of the Book
  // outfile << myBooks.getContent(); // outfiles the content
  myShelf.getBooks(); // gets books on shelves
  myShelf.searchfor();
}
