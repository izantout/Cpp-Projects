#ifndef INFORMATION_H
#define INFORMATION_H
#include <string>

class Information{
  public:

    // Defualt Constructor
    Information();

    // Overloaded Contructor
    Information(std::string mAddress, std::string mLogo, std::string mNumber, std::string mManagerName, std::string mDate, std::string mTime, std::string mCoupons, double mTax);

    // Destructor
    ~Information();

    // Getters
    std::string getAddress();
    std::string getLogo();
    std::string getNumber();
    std::string getName();
    std::string getdate();
    std::string getTime();
    std::string getcoupons();
    double getTax();

    // Setters
    void setAddress(std::string Address);
    void setLogo(std::string Logo);
    void setNumber(std::string Number);
    void setManagerName(std::string ManagerName);
    void setDate(std::string Date);
    void setTime(std::string Time);
    void setcoupons(std::string Coupons);
    void setTax(double Tax);

    //toString functions
    std::string toStringTop();
    std::string toStringMiddle();
    std::string toStringBottom();

  private:
    std::string Address;
    std::string Logo;
    std::string Number;
    std::string Name;
    std::string Date;
    std::string Time;
    std::string Coupons;
    double Tax;
};

#endif
