/**
 * @file 04_DepartmentImpl.cpp
 * @brief Implementation of `Department::PrintDepartment`.
 */

#include "02_DepartmentHeader.cpp"
#include <iostream>

void Department::PrintDepartment() const
{
    std::cout << "Department name " << name
              << " has " << deps.size() << " Employees\n";
}