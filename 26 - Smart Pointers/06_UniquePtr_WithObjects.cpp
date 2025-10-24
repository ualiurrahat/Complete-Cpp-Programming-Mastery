/**
 * @file 06_UniquePtr_WithObjects.cpp
 * @brief `unique_ptr` with custom classes and `make_unique`.
 *
 * Problem Statement:
 * Manage objects with `unique_ptr` — preferred over raw `new`.
 *
 * New Topics Introduced:
 * - `make_unique<Class>(args)` → constructs in-place
 * - Arrow operator `->` for member access
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <memory>
using namespace std;

struct Employee {
    int id;
    string name;
    Employee(int i, string n) : id(i), name(n) {}
    void print() { cout << id << " " << name << "\n"; }
};

int main() {
    auto emp = make_unique<Employee>(10, "Ali");
    emp->print();           // 10 Ali
    (*emp).print();         // same

    return 0;
}