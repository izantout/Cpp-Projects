#ifndef BARCODE_H
#define BARCODE_H
#include <iostream>
#include <string>

class Barcode{
  public:
    // Default constructor
    Barcode();
    
    //Overloaded Constructor
    Barcode(std::string mdate, std::string mtime, std::string memployeeName, std::string mcashierNumber);
    
    // Desturtcor
    ~Barcode();

    // Getters
    std::string getBarcode();
    std::string getDate();
    std::string getTime();
    std::string getName();
    std::string getNumber();
    
    // Setters
    void setBarcode();
    void setDate(std::string mdate);
    void setTime(std::string mtime);
    void setName(std::string mname);
    void setNumber(std::string mnumber);

  private:
    std::string barcode;
    std::string date;
    std::string ptime;
    std::string employeeName;
    std::string cashierNumber;
};


#endif 
