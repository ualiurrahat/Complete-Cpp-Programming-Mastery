/**
 * @file 01_EmployeeHeader.cpp
 * @brief Header for `Employee` and `Department` – uses **forward declaration**.
 *
 * @note `struct Department;` allows `Employee` to hold a `vector<Department>` without full definition.
 * @note Full `Department` definition comes **after** `Employee` in this file.
 * @note `using namespace std;` is **avoided** in headers.
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
#include <vector>

// Forward declaration – tells compiler "Department exists"
struct Department;

struct Employee
{
    std::string name;
    std::vector<Department> deps; // OK: only needs incomplete type

    Employee(std::string name_);
    void Print() const;
};

struct Department
{
    std::string name;
    std::vector<Employee> deps; // Full type needed here

    void PrintDepartment() const;
};

/** @brief Global pointer to a dynamically allocated Employee. */
extern Employee *emp_glob;

#endif /* EMPLOYEE_H_ */