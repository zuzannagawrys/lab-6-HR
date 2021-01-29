#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "..\include\lab6_ZG.h"

using namespace std;


//KLASA EMPLOYEE

    Employee::Employee(string nam, string sur, string posit, string id) :
    ID(id),name(nam), surname(sur), position(posit) 
    {}
    
    Employee::Employee() :
    ID("NULL"), name("NULL"), surname("NULL"), departmentID("NULL"), position("NULL")
    {}

    void Employee::PrintEmployee()
    {
        cout << endl << "+-----------------------------------------------+"<<endl
        << " \t " <<        this->ID << endl
        << " \t " <<        this->name << " " << this->surname<<endl
        << " \t " <<        this->departmentID << " " << this->position<<endl
        <<              "+-----------------------------------------------+"<<endl;
    }

    string Employee::GetEmployeeID()
    {
        return this->ID;
    }

    void Employee::SetDepartmentID(string dpID)
    {
        this->departmentID = dpID;
    }


//KLASA HRMS

    void HRMS::add(Employee employee, string departmentID, double salary)
    {
        employee.SetDepartmentID( departmentID );
        employees[employee.GetEmployeeID()] = employee;
        dep_employees[departmentID].push_back(employee.GetEmployeeID());
        salaries[employee.GetEmployeeID()]=salary;
    }

    void HRMS::printDepartment(string depId)
    {
        cout << "Employees from department:\tID " << depId << endl;
        for( int i=0; i<dep_employees[depId].size(); i++ )
            employees [dep_employees[depId][i]].PrintEmployee();
        cout << endl;
    }

    void HRMS::printSalaries()
    {
        //iterating using pointer to beginning of salaries.
        cout << "Salaries: \n";
        for( auto ptr = salaries.begin(); ptr != salaries.end(); ptr++ )
            {
                employees[ptr->first].PrintEmployee();
                cout << "Salary: " << ptr->second << endl;
            }
        cout << endl;
    }

    bool sortBySalary(pair <string, double> &a, pair <string, double> &b)
    {
        return(a.second > b.second);
    }

    void HRMS::printSalariesSorted()
    {
        cout << "Sorted salaries: \n";
        vector <pair <string, double>> tempvec;
        for ( auto pnt=salaries.begin(); pnt != salaries.end(); ++pnt )
            tempvec.push_back(make_pair(pnt->first,pnt->second));

        sort (tempvec.begin(), tempvec.end(), sortBySalary);
        for( size_t i=0;i<tempvec.size();i++ )
        {
            employees[tempvec[i].first].PrintEmployee();
            cout << "Salary: " << tempvec[i].second << endl;
        }
        cout << endl;
    }

    void HRMS::changeSalary(string employeeID, double new_salary)
    {
        this->salaries[employeeID]=new_salary;
    }

    