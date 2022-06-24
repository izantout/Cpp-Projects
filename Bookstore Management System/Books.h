#ifndef BOOKS_H
#define BOOKS_H

#include <string>

using namespace std;

class Books{
  private:
    string Name;
    string AuthorName;
    string AuthorLast;
    int Pages;
    double Price;
    string Content;
    int inventory;
    string bookNumber;

  public:
    Books(){
      
    }

    Books(string mName){
      Name = mName;
    }

    Books(string mName, string mbookNumber){
      Name = mName;
      bookNumber = mbookNumber;
    }

    Books(string mName, string mAuthorName, string mAuthorLast, int mPages, double mPrice, int minventory, string mbookNumber){
      Name = mName;
      AuthorName = mAuthorName;
      AuthorLast = mAuthorLast;
      Pages = mPages;
      Price = mPrice;
      inventory = minventory;
      bookNumber = mbookNumber;
    }

    Books(string mName, string mAuthorName, string mAuthorLast, int mPages, double mPrice, string mContent, int minventory, string mbookNumber){
      Name = mName;
      AuthorName = mAuthorName;
      AuthorLast = mAuthorLast;
      Pages = mPages;
      Price = mPrice;
      Content = mContent;
      inventory = minventory;
      bookNumber = mbookNumber;
    }

    ~Books(){
      
    }

    string getName(){
      return Name;
    }
    string getAuthor(){
      return AuthorName + ", " + AuthorLast;
    }

    int getPages(){
      return Pages;
    }

    double getPrice(){
      return Price;
    }

    string getContent(){
      return Content;
    }

    string getNumber(){
      return bookNumber;
    }

    int getInventory(){
      return inventory;
    }

    void setName(string mname){
      Name = mname;
    }

    void setAuthor(string mAuthorFirst, string mAutherLast){
      AuthorName = mAuthorFirst;
      AuthorLast = mAutherLast;
    }

    void setPages(int mpages){
      Pages = mpages;
    }

    void setPrice(double mprice){
      Price = mprice;
    }

    void setContent(string mContent){
      Content = pageMaker(mContent);
    }

    void setInventory(int mInventory){
      inventory = mInventory;
    }

    string pageMaker(string mContent){
      string final;
      int spaceCount = 0;
      int pageCount = 1;
      for (char i : mContent){
        final.push_back(i);
        if (i == ' '){
          spaceCount ++;
          final.push_back(i);
        }
        if (spaceCount >= 100){
          final.push_back('\n');
          final.push_back('\n');
          final += "                                                     Page ";
          final += to_string(pageCount);
          final.push_back('\n');
          final.push_back('\n');
          pageCount ++;
          spaceCount = 0;
        }
      }
      final.push_back('\n');
      final.push_back('\n');
      final += "                                                     Page ";
      final += to_string(pageCount);
      return final;
    }
};


#endif
