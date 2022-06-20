#ifndef BOOKS_H
#define BOOKS_H

#include <string>

class Books{
  private:
    std::string Name;
    std::string AuthorName;
    std::string AuthorLast;
    int Pages;
    double Price;
    std::string Content;
    int inventory;
    std::string bookNumber;

  public:

    Books();
    Books(std::string mName);
    Books(std::string mName, std::string mbookNumber);
    Books(std::string mName, std::string mAuthorName, std::string mAuthorLast, int mPages, double mPrice, int minventory, std::string mbookNumber);
    Books(std::string mName, std::string mAuthorName, std::string mAuthorLast, int mPages, double mPrice, std::string mContent, int minventory, std::string mbookNumber);
    ~Books();

    std::string getName();
    std::string getAuthor();
    int getPages();
    double getPrice();
    std::string getContent();
    std::string getNumber();
    int getInventory();

    void setName(std::string mname);
    void setAuthor(std::string mAuthorfirst,            std::string mAutherLast);
    void setPages(int mpages);
    void setPrice(double mprice);
    void setContent(std::string mContent);
    void setInventory(int mInventory);

};


#endif
