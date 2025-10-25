/**
 * @file 02_DepartmentHeader.cpp
 * @brief Header for `Department` – includes `Employee.h` for full `Employee` type.
 *
 * @note `Department` stores `vector<Employee>` → needs full `Employee` definition.
 */

#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_

#include "01_EmployeeHeader.cpp"
#include <string>
#include <vector>

struct Department
{
    std::string name;
    std::vector<Employee> deps; // Full type required

    void PrintDepartment() const;
};

#endif /* DEPARTMENT_H_ */