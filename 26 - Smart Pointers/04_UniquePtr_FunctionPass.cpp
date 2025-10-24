/**
 * @file 04_UniquePtr_FunctionPass.cpp
 * @brief Safe ways to pass `unique_ptr` to functions.
 *
 * Problem Statement:
 * Avoid accidental ownership loss when passing `unique_ptr`.
 *
 * New Topics Introduced:
 * - **Pass by value**: Transfers ownership (use `std::move`)
 * - **Pass by reference**: Keeps ownership
 * - **Pass by `const&`**: Safe observation
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <memory>
using namespace std;

void print_val(unique_ptr<int> p) {      // Takes ownership
    cout << *p << "\n";
}

void print_ref(unique_ptr<int>& p) {     // No ownership change
    cout << *p << "\n";
    p.reset();  // Can modify!
}

void print_const(const unique_ptr<int>& p) {
    cout << *p << "\n";
    // p.reset();  // ERROR
}

int main() {
    auto p = make_unique<int>(20);

    // print_val(p);           // ERROR: copy
    print_val(std::move(p));   // OK: give away ownership

    p = make_unique<int>(30);
    print_ref(p);              // OK: still own after call
    print_const(p);            // OK: safe view

    return 0;
}