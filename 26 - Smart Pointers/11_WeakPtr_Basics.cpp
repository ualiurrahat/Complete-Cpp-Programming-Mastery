/**
 * @file 11_WeakPtr_Basics.cpp
 * @brief `std::weak_ptr` — breaks circular references.
 *
 * Problem Statement:
 * Avoid memory leak from `shared_ptr` cycles.
 *
 * New Topics Introduced:
 * - `weak_ptr<T>`: non-owning reference
 * - `lock()` → `shared_ptr` if alive
 * - `expired()` → check if destroyed
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <memory>
using namespace std;

struct Department;
struct Employee {
    weak_ptr<Department> dept;
    ~Employee() { cout << "Emp destroyed\n"; }
};
struct Department {
    vector<shared_ptr<Employee>> emps;
    ~Department() { cout << "Dept destroyed\n"; }
};

int main() {
    auto e = make_shared<Employee>();
    auto d = make_shared<Department>();

    e->dept = d;
    d->emps.push_back(e);

    // No cycle: d owns e, e weakly refers to d
    return 0;
    // Output: Emp destroyed → Dept destroyed
}