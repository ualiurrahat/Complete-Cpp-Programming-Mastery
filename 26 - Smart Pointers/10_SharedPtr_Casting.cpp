/**
 * @file 10_SharedPtr_Casting.cpp
 * @brief Polymorphic casting with `shared_ptr`.
 *
 * Problem Statement:
 * Safe downcasting with `dynamic_pointer_cast`.
 *
 * New Topics Introduced:
 * - `dynamic_pointer_cast<T>()`
 * - `static_pointer_cast<T>()`
 * - Count increases on successful cast
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <memory>
using namespace std;

struct Person { virtual ~Person() = default; };
struct Employee : Person {};

int main() {
    shared_ptr<Person> p = make_shared<Employee>();
    auto emp = dynamic_pointer_cast<Employee>(p);

    if (emp)
        cout << p.use_count() << " " << emp.use_count() << "\n";  // 2 2

    return 0;
}