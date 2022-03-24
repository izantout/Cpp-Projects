#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
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
    Employee(std::string id, std::string name, double salary/*BankAccount* a*/);
    ~Employee();
    /*
    * Deposits one month's salary into the bank account.
    */
    void deposit_monthly_salary();
    /*
    * Prints this employee's information to cout.
    */
    void print() ;
    void EmployeeInfo() const;
    void getID();
    void getName();
    void get

    friend std::ostream& operator<<(std::ostream& os, const Employee& myEmployee);

  private:
    std::string id;
    std::string name;
    double salary;
    //BankAccount* account;

};


#endif
