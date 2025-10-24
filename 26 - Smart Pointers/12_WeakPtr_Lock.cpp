/**
 * @file 12_WeakPtr_Lock.cpp
 * @brief Safely access object via `weak_ptr::lock()`.
 *
 * Problem Statement:
 * Use `weak_ptr` to observe without preventing destruction.
 *
 * New Topics Introduced:
 * - `lock()` → returns `shared_ptr` or empty
 * - Thread-safe observation pattern
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
    void print() {
        if (auto d = dept.lock()) {
            cout << "Dept has " << d->emps.size() << " employees\n";
        } else {
            cout << "Department gone\n";
        }
    }
};
struct Department {
    vector<shared_ptr<Employee>> emps;
};

int main() {
    auto e = make_shared<Employee>();
    auto d = make_shared<Department>();
    d->emps.push_back(e);
    e->dept = d;

    e->print();  // Dept has 1 employees
    d = nullptr;
    e->print();  // Department gone

    return 0;
}