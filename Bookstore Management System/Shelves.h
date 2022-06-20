#ifndef SHELVES_H
#define SHELVES_H

#include <string>
#include <vector>
#include "Books.h"

class Shelves{
  private:
    std::vector<Books> myBooks;
    std::vector<std::string> myBookNames;
  public:
    Shelves();
    Shelves(std::vector<Books> myBooks);
    ~Shelves();
    void getBooks();
    void setBooks(std::vector<Books> mmyBooks);
    void orderBooks(std::vector <Books> myBooks);
    void searchfor();
    void searchforE();
    //void checkoutBook(std::string bookName);

    friend bool operator==(const std::string& left, const std::string& right);

};

#endif
