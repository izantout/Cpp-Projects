#include "Data.h"
#include <iostream>

using namespace std;
    /*
     * Date Destructor
     */
Date::~Date(){
  
}

    /*
     * Date Default Constructor 
     * Default date is 1/1/1
     */
Date::Date():Date(1, 1, 1){
  
}

    /*
      * Constructs a date with a day, month, and year
      @param newDay the day
      @param newMonth the month
      @param newYear the year
    */
Date::Date(int newDay, int newMonth, int newYear){
  if(validateDate(newDay, newMonth, newYear))
    {
      day = newDay;
      month = newMonth;
      year = newYear;
    }
}

    /*
      * Validates a date's day, month, and year
      @param day the day
      @param month the month
      @param year the year
    */
int Date::validateDate(int day, int month, int year)
{
  try
    {
      if (day > daysInAMonth() || day < 1 || month < 1 || month > 12 || year < 0)
      {
        throw Date::InvalidDateException();
      }
      return 1;
      // Date mydate(day,month,year);
    }
  catch(Date::InvalidDateException)
    {
      cerr << "Invalid Date!" << endl;
    }
  return 0;
}

    /*
      * Give sthe days in each month taking into consideration the leap year
    */
int Date::daysInAMonth()
{
    switch (month)
      {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
          return 31;
        break;
        
        case 2:
          if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
              return 29;
          else
              return 28;
        break;
        
        default:
          return 30;
        break;
        
      }
  return 0;
}

    /*
      * Gets the day
    */
int Date::getDay() const{
  return day;
}

    /*
      * Gets the month
    */
int Date::getMonth() const{
  return month;
}

    /*
      * Gets the year
    */
int Date::getYear() const{
  return year;
}

    /*
      * Sets the day after validating it to be valid
      @ param newDay the day
    */
void Date::setDay(int newDay){
  if(validateDate(newDay, month, year))
    {
      day = newDay;
    }
}

    /*
      * Sets the month after validating it to be valid
      @ param newMonth the month
    */
void Date::setMonth(int newMonth){
  if(validateDate(day, newMonth, year))
    {
      month = newMonth;
    }
}

    /*
      * Sets the year after validating it to be valid
      @ param newYear the year
    */
void Date::setYear(int newYear){
  if(validateDate(day, month, newYear))
    {
      year = newYear;
    }
}

    /*
      * Returns the date formatted nicely in 1 of 4 formats
      @ param format the format selection
    */
string Date::toString(int format){
  switch (format){
    case 1: 
      return to_string(year) + "/" + to_string(month) + "/" + to_string(day);
      
    break;
    
    case 2:
      return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    break;

    case 4:
      return NumberToName() + " " + to_string(day) + ", " + to_string(year);
    
    default:
      return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    break;
  }
  
}

    /*
      * Transforms a month from a number to a name
    */
string Date::NumberToName()
{
    string NameOfMonth[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return (NameOfMonth[month]);
}

// Overloaded Operator
  // << Operator
    /*
      * Overloads the << output operator
      @param os for ostream
      @param myDate for the date
    */
    ostream& operator<<(ostream& os, Date& myDate){
      os << myDate.toString(4);
      return os;
    }

  // << Operator
    /*
      * Overloads the >> input operator
      @param is for istream
      @param myDate for the date
    */
    istream& operator>>(istream& is, Date& myDate){
      int day, month, year;
      is >> day;
      myDate.setDay(day);
      is >> month;
      myDate.setMonth(month);
      is >> year;
      myDate.setYear(year);
      return is;
    }

  // + Operator
    /*
      * Overloads the + operator to add a certain amount of days to the date
      @param myDate for the date
      @param num for the added number
    */
    Date operator+(Date myDate, int num)
    {
      int m;
      while (num > (myDate.daysInAMonth() - myDate.getDay()))
      {
         num -= myDate.daysInAMonth();
         m = myDate.getMonth();
         if (m < 12)
         {
           myDate.setMonth(m + 1);
         }
         else
         {
           myDate.setMonth(1);
           myDate.setYear(myDate.getYear() + 1);
         }
      }
      myDate.setDay(myDate.getDay() + num);
      return myDate;
    }

    /*
      * Subtracts one month from the dates month
    */
    Date Date::subtractMonth()
    {
      if (month > 1)
      {
        month--;
      }
      else
      {
        month = 12;
        year--;
      }
      return *this;
    }

  // - Operator
    /*
      * Overloads the - operator to subtract a certain number from the date
      @param myDate for the date
      @param num for the subtracted number
    */
    Date operator-(Date myDate, int num){
      Date a(myDate.getDay(), myDate.getMonth(), myDate.getYear());
      a = a.subtractMonth();
      while (num > a.daysInAMonth())
      { 
        num -= a.daysInAMonth();
        myDate = myDate.subtractMonth();
        a = a.subtractMonth();
      }
      if (num < myDate.getDay())
      {
        myDate.setDay(myDate.getDay() - num);
      }
      else
      {
        num = num - myDate.getDay();
        myDate = myDate.subtractMonth();
        myDate.setDay(myDate.daysInAMonth() - num);
      }
      return myDate;
    }

  // ++ Operator
    /*
      * Overloads the ++ operator to add 1 to the date
      @param myDate for the date
    */
    Date operator++(Date myDate){
      return myDate + 1;
    }

    /*
      * Overloads the ++ operator to add 1 to the date
      @param myDate for the date
      @param i for the compiler to see the difference between ++x and x++
    */
    Date operator++(Date myDate, int i){
      return myDate + 1;
    }

  // -- Operator
    /*
      * Overloads the -- operator to subtract 1 from the date
      @param myDate for the date
    */
    Date operator--(Date myDate){
      return myDate - 1;
    } 

    /*
      * Overloads the -- operator to subtract 1 from the date
      @param myDate for the date
      @param i for the compiler to see the difference between --x and x--
    */
    Date operator--(Date myDate, int i){
      return myDate - 1;
    } 
