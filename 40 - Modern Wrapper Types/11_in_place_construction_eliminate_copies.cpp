// 11_in_place_construction_eliminate_copies.cpp
/**
 * @file 11_in_place_construction_eliminate_copies.cpp
 * @brief Uses std::in_place to construct optional objects directly in storage.
 *
 * `std::in_place` tells `optional` to construct the contained object **in-place**
 * using perfect forwarding. This avoids creating temporaries and move/copy.
 *
 * Key benefit: **Zero overhead** — only one constructor and one destructor.
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
    Employee(Employee &&) { cout << "Employee &&" << endl; }
    ~Employee() { cout << "~Employee" << endl; }
};

int main()
{
    cout << "=== Empty optional ===" << endl;
    optional<Employee> emp1{};

    cout << "\n=== in_place construction ===" << endl;
    optional<Employee> emp2{in_place, "Hani", 20};
    /*
     * Output:
     *   Employee constructed: Hani, salary=20
     *   ~Employee (at scope exit)
     *   ~Employee (optional destruction)
     * → Only one construction, no copies/moves!
     */

    cout << "\n=== in_place with vector ===" << endl;
    optional<vector<int>> opt{in_place, {4, 1, 20, 30}};
    // Vector constructed directly inside optional

    return 0;
}