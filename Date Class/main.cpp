/*
 * This C++ program will take a year, output all dates in that year, add days to a date, subtact days
 * from a date, and output the date in different formats
 * CECS 275 - Spring 2022
 * @author Issam Zantout
 * @author Ryan Kaia
 */
#include "Data.h"
#include <iostream>

using namespace std;
enum months
  {
    jan,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
  };

// Prototypes
void validateDate(int day,int month,int year, int format);
int daysInAMonth (int month, int year);
void printDays(int year);
string NumberToName(int month);
void printSeason(months months);

int main() 
{
  Date mydate, adate;
  int day, month, year, numToAdd, yearToShow;
  // cout << "Enter a year you want the calendar for: ";
  // cin >> yearToShow;
  // printDays(yearToShow);
  cout << endl << "Enter a Date (Day Month Year): ";
  cin >> mydate;
  // Checks if the date entered is valid or not
  if (mydate.validateDate(mydate.getDay(), mydate.getMonth(), mydate.getYear()))
  {
    cout << "With format 1: " << mydate.toString(1) << endl;
    cout << "With format 2: " << mydate.toString(2) << endl;
    cout << "With format 3: " << mydate.toString(3) << endl;
    cout << "With format 4: " << mydate << endl;
    cout << endl;
    cout << "Enter a number of days to add to the current date: ";
    cin >> numToAdd;
    adate = mydate + numToAdd;
    cout << mydate << " + " << numToAdd << " days = " << adate << endl;
    adate = ++mydate;
    cout << "(++)" << mydate << " = " << adate << endl;
    adate = mydate++;
    cout << mydate << "(++) = " << adate << endl;
    adate = mydate - numToAdd;
    cout << mydate << " - " << numToAdd << " days = " << adate << endl;
    adate = --mydate;
    cout << "(--)" << mydate << " = " << adate << endl;
    adate = mydate--;
    cout << mydate << "(--) = " << adate << endl;
  }
    // if its not valid
  else
  {
    cout << "No format for an invalid date! We cant add numbers to an invalid date!" << endl;
  }
  //cout << "June is in: ";
  //printSeason(jun);
  return 0;
}


// Function Definitions
// For loop that outputs the days of each month in that given year
void printDays(int year)
{
  Date name(1,1,year);
  for (int month=1;month<=12;month++) // Keeps track of the months
    {
      name.setMonth(month);
      int TotalDays = name.daysInAMonth();
      cout << name.NumberToName() << " " << year << ": " << endl;
      for (int day=1;day<=TotalDays;day++) // keeps track of the days of that month
        {
          cout << day << "/" << month << "/" << year << " ";
        }
      cout << endl;
    }
}


// Function that prints the season of a month
void printSeason(months months)
{
    if (months == months::dec || months <= months::feb)
      {
        cout << "Winter!" << endl;
      }
    else if (months >= months::mar && months <= months::may)
      {
        cout << "Spring!" << endl;
      }
    else if (months >= months::jun && months <= months::aug)
      {
        cout << "Summer!" << endl;
      }
    else if (months >= months::sep && months <= months::nov)
      {
        cout << "Fall!" << endl;
      }
    else
      {
       cout << "Please be careful how you input the month. Please enter the month with the format of the first 3 letters typed in lowercase." << endl;
      }
  }
