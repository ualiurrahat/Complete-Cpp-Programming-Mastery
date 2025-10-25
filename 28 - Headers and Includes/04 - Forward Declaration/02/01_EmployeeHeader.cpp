/**
 * @file 01_EmployeeHeader.cpp
 * @brief Header for `Employee` – uses **forward declaration** of `Department`.
 *
 * @note `struct Department;` allows `Employee` to hold `vector<Department*>`.
 * @note Full `Department` definition is in `Department.h`.
 * @note `using namespace std;` is **avoided** in headers.
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
#include <vector>

// Forward declaration – incomplete type
struct Department;

struct Employee
{
    std::string name;
    std::vector<Department *> deps; // Pointers: only need incomplete type

    Employee(std::string name_);
    void Print() const;
};

/** @brief Global pointer to a dynamically allocated Employee. */
extern Employee *emp_glob;

#endif /* EMPLOYEE_H_ */