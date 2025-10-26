/**
 * @file 20_DeletedDoubleCtor.cpp
 * @brief Uses `= delete` to **disable** a constructor that would allow implicit conversion.
 *
 * - `Employee(double, string)` is **deleted**
 * - Prevents accidental construction from floating-point salary
 * - Compile-time safety
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Employee
{
private:
    int *salary{nullptr};
    string name;

public:
    Employee() = default;

    /** @brief Deleted: no double salary allowed. */
    Employee(double, string) = delete;

    Employee(int salary_val, string name_val)
        : salary(new int{salary_val}), name(move(name_val))
    {
    }

    ~Employee()
    {
        delete salary;
        salary = nullptr;
    }

    int GetSalary() const { return salary ? *salary : 0; }
    const string &GetName() const { return name; }
};

int main()
{
    Employee e1(10, "Mostafa"); // OK

    // Employee e2(10.5, "Mostafa");  // ERROR: use of deleted function

    cout << e1.GetName() << "'s salary: " << e1.GetSalary() << "\n";

    return 0;
}