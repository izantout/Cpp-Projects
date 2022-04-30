#ifndef RECEIPT_H
#define RECEIPT_H
#include "Products.h"
#include <iostream>
#include <string>
#include <vector>

class Receipt{
  public:
    Receipt();
    Receipt(std::string mheader, std::vector<Products> mbuySummary, std::string mbarcode, std::string mfooter, double tax);
    ~Receipt();

    // Getters
    std::string getHeader();
    std::vector<Products> getSummary();
    std::string getBarcode();
    std::string getFooter();
    std::string getPayment();
    double getTax();
    
    // Setters
    void setHeader(std::string mheader);
    void setSummary(std::vector<Products> mmyProducts);
    void setBarcode(std::string mBarcode);
    void setFooter(std::string mFooter);
    void setTax(double mTax);
    void setPayment(std::string mPayment);

    //toString Function
    std::string toString();
    std::string Summary();

  private:
    std::string header;
    std::vector<Products> buySummary;
    std::string barcode;
    std::string footer;
    double tax;
    std::string payment;
};

#endif
