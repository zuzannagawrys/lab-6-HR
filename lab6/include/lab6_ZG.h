#include <map>
#include <vector>

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


class Employee{

public:
    string ID;
    string name;
    string surname;

    string departmentID; //identyfikator działu
    string position;   //stanowisko

    Employee(string id, string name, string surname, string position);
    Employee();

    void PrintEmployee();
    void SetDepartmentID(string dpID);
    string GetEmployeeID();
};


class HRMS{

    map <string, Employee> employees;
    map <string, double > salaries;
    map <string, vector <string> > dep_employees;

public:
    void add(Employee employee, string departmentID, double salary);
    void printDepartment(string departmentID);
    
    void printSalaries();
    void printSalariesSorted(); //z użyciem std::algorithm

    void changeSalary(string employeeID, double new_salary);

};