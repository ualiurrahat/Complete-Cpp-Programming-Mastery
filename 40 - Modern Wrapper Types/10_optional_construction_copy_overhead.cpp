// 10_optional_construction_copy_overhead.cpp
/**
 * @file 10_optional_construction_copy_overhead.cpp
 * @brief Demonstrates unnecessary copy/move during optional construction.
 *
 * When initializing `optional<T>` with a temporary object (e.g., `Employee{"Hani", 20}`),
 * C++ may create a temporary, then copy/move it into the optional — even with RVO.
 * This example shows the **extra constructor and destructor calls**.
 *
 * Goal: Highlight the problem solved by `in_place` construction.
 */

#include <iostream>
#include <vector>
#include <optional>
#include <string>
using namespace std;

struct Employee
{
    /**
     * @brief Constructs an Employee with name and salary.
     * @note Prints to track object lifetime.
     */
    Employee(string name, int salary)
    {
        cout << "Employee constructed: " << name << ", salary=" << salary << endl;
    }

    /** @brief Move constructor — tracks moves */
    Employee(Employee &&emp) noexcept
    {
        cout << "Employee && (move)" << endl;
    }

    /** @brief Destructor — tracks cleanup */
    ~Employee()
    {
        cout << "~Employee" << endl;
    }
};

int main()
{
    cout << "=== Creating empty optional ===" << endl;
    optional<Employee> emp1{}; // No object created

    cout << "\n=== Creating optional with temporary Employee ===" << endl;
    // Problem: Temporary Employee is created, then moved into optional
    optional<Employee> emp2{Employee{"Hani", 20}};
    /*
     * Expected output:
     *   Employee constructed: Hani, salary=20
     *   Employee && (move)
     *   ~Employee (temporary destroyed)
     *   ~Employee (optional destroyed at end)
     */

    cout << "\n=== Optional with vector ===" << endl;
    optional<vector<int>> opt{vector<int>{4, 1, 20, 30}};
    // Same issue: vector temporary is moved in

    return 0;
}