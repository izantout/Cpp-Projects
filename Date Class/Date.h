#ifndef DATE_H
#define DATE_H
#include <fstream>
#include <string>

class Date{
  public:
// Constructors
  // Default Constructor
    Date();

  // Overloaded Constructor
    Date(int newDay, int newMonth, int newYear);

// Destructor
    ~Date();

// Getters
  // Day
    int getDay() const;

  // Month
    int getMonth() const;

  // Year
    int getYear() const;

// Setters
  // Day
    void setDay(int newDay);

  // Month
    void setMonth(int newMonth);

  // Year
    void setYear(int newYear);

// ToString function that takes a date as 3 integers and returns them as a string formatted nicely
    std::string toString(int format);
    int daysInAMonth ();
    int validateDate(int day, int month, int year);
    std::string NumberToName();
// Exception Classes
  // Invalid Date
    class InvalidDateException{
      
    };

// Overloaded Operator
  // << Operator
    friend std::ostream& operator<<(std::ostream& os, Date& myDate);

  // << Operator
    friend std::istream& operator>>(std::istream& os, Date& myDate);


  // + Operator
    friend Date operator+(Date myDate, int num);
  // - Operator
    friend Date operator-(Date myDate, int num);

  // ++ Operator
    friend Date operator++(Date myDate);
    friend Date operator++(Date myDate, int i);

    Date subtractMonth();
  // -- Operator
    friend Date operator--(Date myDate);
    friend Date operator--(Date myDate, int i);


  private:

    int day;
    int month;
    int year;
};
#endif
