/**
 * @file 04_DepartmentImpl.cpp
 * @brief Implementation of `Department::PrintDepartment`.
 */

#include "01_EmployeeHeader.cpp"
#include <iostream>

void Department::PrintDepartment() const
{
    std::cout << "Department: " << name << "\n";
}