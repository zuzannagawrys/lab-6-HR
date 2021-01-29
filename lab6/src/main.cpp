#include <iostream>
#include <string>
#include <vector>

#include "..\include\lab6_ZG.h"

using namespace std;

int main()
{
    HRMS DB;

    Employee employees[11] ={
        {"Mariusz","Sokal","programista","0"},
        {"Jan","Kowalcze","elektryk","1"},
        {"Maria","Kalna","programista","2"},
        {"Karol","Sotwin","kierowca","3"},
        {"Karolina","Schulz","dyrektor","4"},
        {"Marek","Konopinski","manager","5"},
        {"Michal","Ogorek","www_dev","6"},
        {"Mateusz","Kaplan","stazysta","7"},
        {"Karol","Polak","ksiegowy","8"},
        {"Aleksander","Emmanuel","elektryk","9"},
        {"Marian","Pala","programista","10"}
    };

    DB.add(employees[0], "IT", 6100.0);
    DB.add(employees[1], "OTHER", 2750.5);
    DB.add(employees[2], "IT", 7100.0);
    DB.add(employees[3], "LOGISTICS", 3050.0);
    DB.add(employees[4], "MANAGEMENT", 26100.0);
    DB.add(employees[5], "MANAGEMENT", 12000.0);
    DB.add(employees[6], "IT", 6100.0);
    DB.add(employees[7], "OTHER", 1450.0);
    DB.add(employees[8], "FINANCE", 3500.6);
    DB.add(employees[9], "OTHER", 26100.0);
    DB.add(employees[10],"IT", 9120.0);
    

    DB.printSalaries();
    DB.printDepartment("OTHER");
        
    cout<<"Changing salary of: "<<endl;
    employees[7].PrintEmployee();
    DB.changeSalary("7", 120000.5);
        
        
    DB.printSalaries();

    DB.printSalariesSorted();

    system("PAUSE");
    return 0;
}
