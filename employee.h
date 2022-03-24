#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "bankAccount.h"
#include <fstream>
#include <vector>

class Employee{
  public:
    Employee();
    /*
      * Constructs an employee with a id, given name, salary, and
      * bank account.
      @param id the id
      @param n the name
      @param s the annual salary
      @param a a pointer to the bank account
    */
    Employee(std::string mid, std::string mfirst, std::string mlast, double msalary, BankAccount* a);
    ~Employee();
    /*
    * Deposits one month's salary into the bank account.
    */
    void deposit_monthly_salary();
    /*
    * Prints this employee's information to cout.
    */
    void print(std::ofstream outfile);
    std::string getID() ;
    std::string getLast() const;
    std::string getFirst() const;
    double getSalary() const;
    BankAccount* getAccount() const;
    void setSalary(double newSalary);

    friend std::ostream& operator<<(std::ostream& os, const Employee& myEmployee);

  private:
    std::string id;
    std::string first;
    std::string last;
    double salary;
    BankAccount* account;

};


#endif
