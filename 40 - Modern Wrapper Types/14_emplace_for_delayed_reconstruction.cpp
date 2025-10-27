// 14_emplace_for_delayed_reconstruction.cpp
/**
 * @file 14_emplace_for_delayed_reconstruction.cpp
 * @brief Uses emplace() to reconstruct optional contents in-place.
 *
 * `optional::emplace(args...)` destroys current value (if any) and constructs
 * a new one in the same storage. Avoids allocation and copies.
 *
 * Useful for resetting or reinitializing large objects.
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
    Employee(const Employee &) = delete;
    Employee(Employee &&) = delete;
};

int main()
{
    cout << "=== Initial emplace ===" << endl;
    optional<Employee> emp;
    emp.emplace("Hani", 20); // First construction

    cout << "\n=== Re-emplace (reconstruct) ===" << endl;
    emp.emplace("Ali", 30); // Destroys old, constructs new in-place

    cout << "\n=== Vector emplace examples ===" << endl;
    optional<vector<int>> v{in_place, {1, 2, 3}};
    v = {3, 4, 5};        // Assignment (move)
    v.emplace({3, 4, 5}); // Reconstruct in-place

    return 0;
}