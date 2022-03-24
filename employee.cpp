#include "employee.h"
#include "bankAccount.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>

using namespace std;

Employee::Employee(string mid, string mfirst, string mlast, double msalary, BankAccount* a){
    id = mid;
    first = mfirst;
    last = mlast;
    salary = msalary;
    account = a;
}

void Employee::print(ofstream outfile) {
  double monthlySalary = 0;
  double bal;
  int width;
      outfile << id << " ";
      outfile << setw(10) << first << " ";
      outfile << setw(11) << last << " ";
      outfile << setprecision(2) << fixed << setw(7) << salary;
  monthlySalary = salary/12;
      outfile << setprecision(2) << fixed << setw(12) << monthlySalary;
  bal = account->get_balance();
      outfile << setprecision(2) << fixed << setw(12) << bal << endl;  
}

ostream& operator<<(ostream& os, const Employee& myEmployee){
  double monthlySalary = 0;
  int width;
      os << myEmployee.id << " ";
      os << setw(10) << myEmployee.getFirst() << " ";
      os << setw(11) << myEmployee.getLast() << " ";
      os << setprecision(2) << fixed << setw(7) << "$" << myEmployee.getSalary();
  monthlySalary = myEmployee.getSalary()/12;
      os << setprecision(2) << fixed << setw(12) << "$" << monthlySalary;
      os << setprecision(2) << fixed << setw(12) << "$" <<
        myEmployee.account->get_balance() << endl;
  return os;
}

string Employee::getID() {
  return id;
}

string Employee::getLast() const{
  return last;
}

string Employee::getFirst() const{
  return first;
}

double Employee::getSalary() const{
  return salary;
}

void Employee::setSalary(double newSalary){
  salary = newSalary;
}

void Employee::deposit_monthly_salary(){
  double sal = getSalary();
  account->deposit(sal/12);
}

Employee::~Employee(){

}
