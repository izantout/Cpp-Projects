#ifndef PRODUCTS_H
#define PRODUCTS_H
#include <string>

class Products{
  public:
    // Defualt Constructor
    Products();

    // Overloaded Constructor
    Products(std::string mName, std::string SNumber, int mQuantity, double mPrice);

    Products(std::string mName, std::string SNumber, double mPrice);
    // Getters
    std::string getName();
    std::string getSNumber();
    int getQuantity();
    double getPrice();
    
    // Setters
    void setName(std::string mName);
    void setSNumber(std::string mNumber);
    void setQuantity(int mQuantity);
    void setPrice(double mPrice);

    // ToString
    std::string toString();

  private:
    std::string name;
    std::string SerialNumber;
    int quantity;
    double price;
};

#endif
