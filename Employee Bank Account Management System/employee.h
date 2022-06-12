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
      @ Param ofstream to outfile
    */
    void print(std::ofstream outfile);
    /*
    * Gets this employee's ID.
    */
    std::string getID() ;
    /*
    * Gets this employee's last name.
    */
    std::string getLast() const;
    /*
    * Gets this employee's first name
    */
    std::string getFirst() const;
    /*
    * Gets this employee's salary.
    */
    double getSalary() const;
    /*
    * Gets this employee's account using pointer
    */
    BankAccount* getAccount() const;
    /*
    * Set's this employees salary.
      @ Param double newSalary if we want to change the salary
    */
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
