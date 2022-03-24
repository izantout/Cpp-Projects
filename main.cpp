#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "employee.h"
#include "bankAccount.h"

using namespace std;

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
  // 
  getline(infile,menu); 
  outfile << menu << "          monthly salary" << "             balance " << endl;
  while(infile >> id >> first >> last >> stringsal){
      stringsal.erase(remove(stringsal.begin(), stringsal.end(), ','), stringsal.end());
      salary = stod(stringsal);
      myAccounts.push_back(BankAccount(id));
      myEmployees.push_back(Employee(id, first, last, salary, &myAccounts[i]));
    i++;
  }
  
  for(int i=0;i<myEmployees.size();i++)
    {
      myEmployees[i].deposit_monthly_salary();
      outfile << myEmployees[i];
    }
  return 0;
}
