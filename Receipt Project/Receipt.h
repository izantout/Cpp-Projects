#ifndef RECEIPT_H
#define RECEIPT_H
#include "Products.h"
#include <iostream>
#include <string>
#include <vector>

class Receipt{
  public:
    Receipt();
    Receipt(std::string mheader, std::vector<Products> mbuySummary, std::string mbarcode, std::string mfooter);
    ~Receipt();

    // Getters
    std::string getHeader();
    std::vector<Products> getSummary();
    std::string getBarcode();
    std::string getFooter();
    
    // Setters
    void setHeader(std::string mheader);
    void setSummary(std::vector<Products> mmyProducts);
    void setBarcode(std::string mBarcode);
    void setFooter(std::string mFooter);

    //toString Function
    std::string toString();
    std::string trial();

  private:
    std::string header;
    std::vector<Products> buySummary;
    std::string barcode;
    std::string footer;
};

#endif
