/**
 * @file 21_DeletedCopyCtor.cpp
 * @brief Deletes copy constructor to prevent object copying.
 *
 * - Useful for classes managing unique resources (file handles, sockets, etc.)
 * - `Employee e2(e1);` → **compilation error**
 * - Enforces **move-only** or **unique ownership**
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

    /** @brief Deleted: no copying allowed. */
    Employee(const Employee &) = delete;

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
    Employee e1(10, "Mostafa");

    // Employee e2(e1);             // ERROR: deleted
    // Employee e3 = e1;            // ERROR

    cout << "Original: " << e1.GetName() << "\n";

    return 0;
}