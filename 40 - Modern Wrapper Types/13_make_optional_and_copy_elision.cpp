// 13_make_optional_and_copy_elision.cpp
/**
 * @file 13_make_optional_and_copy_elision.cpp
 * @brief Uses make_optional with guaranteed copy elision (C++17).
 *
 * `make_optional<T>(args...)` is equivalent to `optional<T>{in_place, args...}`.
 * Thanks to **mandatory copy elision**, no temporary object is created.
 *
 * Even with non-copyable types, it works because construction is direct.
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
    cout << "=== make_optional with Employee ===" << endl;
    auto emp = make_optional<Employee>("Hani", 20);
    /*
     * Output:
     *   Employee constructed: Hani, salary=20
     *   ~Employee
     *   ~Employee
     * → Direct construction, no copies
     */

    cout << "\n=== make_optional with vector ===" << endl;
    auto opt1 = make_optional<vector<int>>({4, 1, 20, 30});
    auto opt2 = make_optional<vector<int>>(4, 1); // 4 elements, value 1

    return 0;
}