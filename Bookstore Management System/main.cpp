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
  Books Book1("Harry potter and the prisoners of azkaban", "J.K.", "Rolling", 500, 19.99, 5, "000001");
  Books Book2("Harry Potter and the goblet of fire", "J.K.", "Rolling", 500, 19.99, 5, "000002");
  Books Book3("Harry Potter and the chamber of secrets", "J.K.", "Rolling", 500, 19.99, 5, "000003");
  Books Book4("Harry Potter and the philosopher's stone", "J.K.", "Rolling", 500, 19.99, 5, "000001");
  
  vector<Books> BooksinLibrary;
  BooksinLibrary.push_back(Book1);
  BooksinLibrary.push_back(Book2);
  BooksinLibrary.push_back(Book3);
  BooksinLibrary.push_back(Book4);
  
// ----- Shelves Section -----
  Shelves myShelf(BooksinLibrary);

// ----- Content Section -----
string myString = "Write whatever paragraph you want here! ";

// ----- 2. Function Calling -----
  myBooks.setContent(myString); // Sets Content of the Book
  outfile << myBooks.getContent(); // outfiles the content
  myShelf.getBooks(); // gets books on shelves
  myShelf.searchfor();
}
