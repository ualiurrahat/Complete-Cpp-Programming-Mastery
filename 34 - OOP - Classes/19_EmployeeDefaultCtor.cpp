/**
 * @file 19_EmployeeDefaultCtor.cpp
 * @brief Shows how `= default` **explicitly requests** the default constructor.
 *
 * - Even with a user-provided constructor, `Employee() = default;` forces generation
 * - Members with in-class initializers (`salary{nullptr}`) are used
 * - Safe and predictable
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Employee
{
private:
    int *salary{nullptr}; ///< Default: null pointer
    string name;          ///< Default: empty string

public:
    /** @brief Explicitly defaulted constructor – uses in-class initializers. */
    Employee() = default;

    /** @brief Parameterized constructor – heap allocation. */
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
    Employee e1;                   // OK: uses = default
    Employee e2(75000, "Mostafa"); // parameterized

    cout << "e1: " << e1.GetName() << ", Salary: " << e1.GetSalary() << "\n"; // empty, 0
    cout << "e2: " << e2.GetName() << ", Salary: " << e2.GetSalary() << "\n";

    return 0;
}