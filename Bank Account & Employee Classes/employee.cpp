#include "employee.h"
#include "bankAccount.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>

using namespace std;

    /*
      * Constructs an employee with a id, given name, salary, and
      * bank account.
      @param id the id
      @param n the name
      @param s the annual salary
      @param a a pointer to the bank account
    */
Employee::Employee(string mid, string mfirst, string mlast, double msalary, BankAccount* a){
    id = mid;
    first = mfirst;
    last = mlast;
    salary = msalary;
    account = a;
}
    /*
    * Prints this employee's information to cout.
      @ Param ofstream to outfile
    */
void Employee::print(ofstream outfile) {
  double monthlySalary = 0;
  double bal;
  int width;
      outfile << id;
      outfile << setw(8) << first;
      outfile << setw(8) << last;
      outfile << setprecision(2) << fixed << setw(8) << salary;
  monthlySalary = salary/12;
      outfile << setprecision(2) << fixed << setw(8) << monthlySalary;
  bal = account->get_balance();
      outfile << setprecision(2) << fixed << setw(8) << bal << endl;  
}

ostream& operator<<(ostream& os, const Employee& myEmployee){
  double monthlySalary = myEmployee.getSalary()/12;
  int width;
      os << setw(10) << myEmployee.id;
      os << setw(10) << myEmployee.getFirst();
      os << setw(14) << myEmployee.getLast();
      os << setw(8)  << fixed << setprecision(2) << "$" << myEmployee.getSalary();
      os << setw(10) << fixed << setprecision(2) << "$" << monthlySalary;
      os << setw(14) << fixed << setprecision(2) << "$" << myEmployee.account->get_balance() << endl;
  return os;
}
    /*
    * Gets this employee's ID.
    */
string Employee::getID() {
  return id;
}
    /*
    * Gets this employee's last name.
    */
string Employee::getLast() const{
  return last;
}
    /*
    * Gets this employee's first name
    */
string Employee::getFirst() const{
  return first;
}
    /*
    * Gets this employee's salary.
    */
double Employee::getSalary() const{
  return salary;
}
    /*
    * Set's this employees salary.
      @ Param double newSalary if we want to change the salary
    */
void Employee::setSalary(double newSalary){
  salary = newSalary;
}
    /*
    * Deposits one month's salary into the bank account.
    */
void Employee::deposit_monthly_salary(){
  double sal = getSalary();
  account->deposit(sal/12);
}

Employee::~Employee(){

}
