/**
 * @file 01_UniquePtr_Basics.cpp
 * @brief Introduction to `std::unique_ptr` — exclusive ownership.
 *
 * Problem Statement:
 * Demonstrate how `unique_ptr` manages a single owner of a resource.
 *
 * New Topics Introduced:
 * - `std::unique_ptr<T>`: RAII wrapper for dynamic memory.
 * - **Exclusive ownership**: Only one `unique_ptr` owns the object.
 * - `make_unique<T>(args)`: Preferred way to create.
 * - `reset()`, `get()`, `release()`
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <memory>
using namespace std;

int main() {
    // Direct initialization (C++14+)
    unique_ptr<int> p1 = make_unique<int>(20);
    cout << *p1 << "\n";     // 20
    *p1 = 50;
    cout << *p1 << "\n";     // 50

    // Replace managed object
    p1.reset(new int{30});
    cout << *p1 << "\n";     // 30

    // Auto cleanup on scope exit
    return 0;
}