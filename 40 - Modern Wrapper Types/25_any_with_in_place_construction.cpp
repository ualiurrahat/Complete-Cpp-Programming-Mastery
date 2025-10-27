// 25_any_with_in_place_construction.cpp
/**
 * @file 25_any_with_in_place_construction.cpp
 * @brief Efficient construction of objects inside std::any.
 *
 * `std::any` requires contained type to be **copyable**.
 * Use `make_any<T>`, `emplace<T>`, or `in_place_type<T>` to avoid copies.
 *
 * This avoids heap allocation for small objects and prevents copy overhead.
 */

#include <iostream>
#include <any>
#include <string>
using namespace std;

struct Employee
{
    Employee(string name, int salary)
    {
        cout << "Employee constructed: " << name << ", salary=" << salary << '\n';
    }
    ~Employee()
    {
        cout << "~Employee\n";
    }
    // Copy/move allowed (default)
};

int main()
{
    cout << "=== make_any (copy elision) ===\n";
    any a1 = make_any<Employee>("Mostafa", 1000);
    // No copy: direct construction in any's storage

    cout << "\n=== emplace (reconstruct in-place) ===\n";
    a1.emplace<Employee>("Mostafa", 1000);
    // Destroys old, constructs new in same storage

    cout << "\n=== in_place_type (explicit) ===\n";
    any a2{in_place_type<Employee>, "Mostafa", 1000};

    return 0;
}