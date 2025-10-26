/**
 * @file 18_EmployeeNoDefaultCtor.cpp
 * @brief Demonstrates that **any user-provided constructor** disables the implicit default constructor.
 *
 * - `Employee(int, string)` is user-provided
 * - Therefore, `Employee e2;` → **compilation error**
 * - The implicit default constructor is **not generated**
 *
 * @note This is a common source of confusion. Always provide `= default` if you want it.
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Employee
{
private:
    int *salary{nullptr}; ///< Heap-allocated salary
    string name;          ///< Employee name

public:
    /** @brief Parameterized constructor – allocates salary on heap. */
    Employee(int salary_val, string name_val)
        : salary(new int{salary_val}), name(move(name_val))
    {
    }

    /** @brief Destructor – clean up dynamic memory. */
    ~Employee()
    {
        delete salary;
        salary = nullptr;
    }

    // Getters (for completeness)
    int GetSalary() const { return salary ? *salary : 0; }
    const string &GetName() const { return name; }
};

int main()
{
    Employee e1(50000, "Mostafa"); // OK: uses parameterized ctor

    // Employee e2;                 // ERROR: no default constructor
    // cout << e2.GetName() << "\n";

    cout << "Employee: " << e1.GetName() << ", Salary: " << e1.GetSalary() << "\n";

    return 0;
}