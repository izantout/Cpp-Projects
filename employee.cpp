#include "employee.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;
vector<Employee> myEmployees;
vector<string> stringVec;
Employee::Employee() : Employee("027941626", "Issam", 25.5){
    
}

Employee::Employee(string mid, string mname, double msalary){
    id = mid;
    name = mname;
    salary = msalary;
}

void Employee::EmployeeInfo() const{
  cout << "ID: " << id << endl;
  cout << "Name: " << name << endl;
  cout << "Salary: " << salary << endl;
}

void Employee::print() {
 ifstream infile("salary.txt");
  ofstream outfile("monthly_salary.txt");
  string id,first,last, name, menu;
  string salary;
  double s, ms, bal;
  vector<Employee> MyEmployees;
  int count, width;
  getline(infile,menu);
  outfile<<menu<< "     Monthly Salary     " << "   Balance" << endl;
  while(infile>>id>>last>>first>>salary)
    {
      outfile << id       <<           " ";
      outfile << setw(10) << first  << " ";
      outfile << setw(11) << last   << " ";
      name = first + " " +last;
      salary.erase(remove(salary.begin(), salary.end(), ','), salary.end());
      s = stod(salary);
      outfile << setprecision(2) << fixed << setw(7) << "$" << s;
      ms = s/12;
      bal = ms+2000;
      outfile << setprecision(2) << fixed << setw(12-salary.length()) << "$" << ms;
      if (ms < 999.99)
      {
        width = 13;
      }
      else if (ms < 9999.99)
      {
        width = 12;
      }
      else if (ms < 99999.99)
      {
        width = 10;
      }
      outfile << setprecision(2) << fixed << setw(width) << "$" << bal << endl;
      stringVec.push_back(id);
      stringVec.push_back(salary);
      
      myEmployees.push_back(Employee(id, name, s));
      
    }
  for (int i=0;i<myEmployees.size();i++)
    {
      cout << myEmployees[i];
    }
}

ostream& operator<<(ostream& os, const Employee& myEmployee){
  os << "ID: " << myEmployee.id << endl;
  os << "Name: " << myEmployee.name << endl;
  os << "Salary: " << myEmployee.salary << endl;
  return os;
}

Employee::~Employee(){
  cout << "Employee is fired! " << endl;
  //delete account;
}
