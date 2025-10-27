// 12_in_place_required_for_non_copyable_types.cpp
/**
 * @file 12_in_place_required_for_non_copyable_types.cpp
 * @brief Shows that in_place is mandatory when T is not copyable/moveable.
 *
 * If `Employee` deletes copy and move constructors, you **cannot** do:
 * `optional<Employee>{Employee{...}}` → compilation error.
 *
 * `in_place` bypasses this by constructing directly in optional's storage.
 */

#include <iostream>
#include <vector>
#include <optional>
#include <string>
using namespace std;

struct Employee
{
    Employee(string name, int salary)
    {
        cout << "Employee constructed: " << name << ", salary=" << salary << endl;
    }
    ~Employee() { cout << "~Employee" << endl; }

    // Delete copy and move → non-copyable, non-movable
    Employee(const Employee &) = delete;
    Employee(Employee &&) = delete;
};

int main()
{
    // This would cause compilation error:
    // optional<Employee> emp1{Employee{"Hani", 20}};

    cout << "=== Using in_place (required) ===" << endl;
    optional<Employee> emp2{in_place, "Hani", 20};
    /*
     * Output:
     *   Employee constructed: Hani, salary=20
     *   ~Employee
     *   ~Employee
     */

    optional<vector<int>> opt{in_place, {4, 1, 20, 30}};

    return 0;
}