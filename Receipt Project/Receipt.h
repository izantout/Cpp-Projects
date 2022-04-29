#ifndef RECEIPT_H
#define RECEIPT_H
#include <iostream>
#include <string>

class Receipt{
  public:
    Receipt();
    Receipt(std::string mheader, std::string mbuySummary, std::string mbarcode, std::string mfooter);
    ~Receipt();

    // Getters
    std::string getHeader();
    std::string getSummary();
    std::string getBarcode();
    std::string getFooter();
    
    // Setters
    void setHeader(std::string mheader);
    void setSummary(std::string mSummary);
    void setBarcode(std::string mBarcode);
    void setFooter(std::string mFooter);

    //toString Function
    std::string toString();

  private:
    std::string header;
    std::string buySummary;
    std::string barcode;
    std::string footer;
};

#endif
