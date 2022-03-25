/*
 * This C++ program outputs employees written in text file, creats a bank account for them and deposits their monthly salary
 * CECS 275 - Fall 2021
 * @author Issam Zantout
 * @author Ryan Kaia <---- Your partner's name
 * @version 1.0.0 
 *
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "employee.h"
#include "bankAccount.h"

using namespace std;

// prototypes
void printEmployees(vector<Employee> myVec, string menu);
void depositMonthlySalary(vector<Employee> myVec);
void addCommas(double amount);


// Function Decleration
void addCommas(double amount)
{
  int intAmount = int(amount); // The int amount of the double passed to the function
  string decimal = to_string(amount-intAmount); // string value of the decimal of that double
  int end;
  string s = to_string(intAmount); // string value of the int amount of the double passed 
  int n = s.length() - 3;


  decimal.resize(4); // resizing to 4 to have the . and 2 0s
  decimal.erase(decimal.begin()); // erase the 0 before the .
  if (amount >= 0) // if amount is positive
  {
    end = 0; 
  }
  else
  {
    end = 1; // if amount is negative
  }
   while (n > end) {
      s.insert(n, ","); // keep inserting commas every 3 places
      n -= 3;
   }
  cout << s << decimal << endl;  // returns the number with commas and 2 decimal points.
  // because we need salary to be a double, this will not be possible to pass that value into the class since commas in a double doesn't work

}

void depositMonthlySalary(vector<Employee> myVec)
{
  for (int i=0;i<myVec.size();i++)
    {
      myVec[i].deposit_monthly_salary(); // deposit the salalry of each employee in the vector Employee
    }
}

void printEmployees(vector<Employee> myVec, string menu)
{
    ofstream outfile("monthly_salary.txt");
    outfile << menu << "          monthly salary" << "          balance " << endl;
    for(int i=0;i<myVec.size();i++)
    { 
      outfile << myVec[i];  // print all the employees that are in the text file
    }
}

int main()
{
  // Variable Decleration
  string menu, id, first, last, stringsal;
  double salary;
  ifstream infile("salary.txt");
  ofstream outfile("monthly_salary.txt");
  BankAccount myAccount("0");
  vector<BankAccount> myAccounts;
  vector<Employee> myEmployees;
  int i = 0;
  getline(infile,menu); // getline from text file to output the menu which is the id last name first name salary monthly salary and balance
  while(infile >> id >> first >> last >> stringsal)
  {
    stringsal.erase(remove(stringsal.begin(), stringsal.end(), ','), stringsal.end()); // erase the comma from the string that we want to turn into a double
    salary = stod(stringsal); // make that string a double
    myAccounts.push_back(BankAccount(id)); // giving the vector of bank accounts the id
    myEmployees.push_back(Employee(id, first, last, salary, &myAccounts[i])); // giving the vector of employees the name, last name, id, salary, and account which is a dereferenced pointer to the vector of employee accounts
    i++;
  }

  
  // Function Calling
  depositMonthlySalary(myEmployees); // function calling to deposit monthly salary into the account
  printEmployees(myEmployees, menu); // printing the employees and the menu in the output text file nicely
  return 0;
}
