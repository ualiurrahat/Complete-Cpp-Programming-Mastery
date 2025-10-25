/**
 * @file 03_EmployeeImpl.cpp
 * @brief Implementation of `Employee` – includes **both** headers.
 *
 * @note `Department.h` is included to get full `Department` type.
 */

#include "01_EmployeeHeader.cpp"
#include "02_DepartmentHeader.cpp"
#include <iostream>

Employee *emp_glob = new Employee("mostafa");

Employee::Employee(std::string name_) : name(name_) {}

void Employee::Print() const
{
    std::cout << "I am " << name << "\n";
    std::cout << "I work in the following departments:\n";
    for (const Department *d : deps)
        d->PrintDepartment();
}