/**
 * @file 15_PointerVsReference.cpp
 * @brief Side-by-side comparison of pointers and references.
 *
 * Problem Statement:
 * Show syntax and behavior differences between `*` and `&`.
 *
 * New Topics Introduced:
 * - Pointer can be `nullptr`, reassigned
 * - Reference cannot be null, cannot rebind
 * - Both can modify original value
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int val = 15;
    int &ref = val;
    int *ptr = &val;

    cout << val << " " << &val << "\n";
    cout << ref << " " << &ref << "\n";
    cout << *ptr << " " << ptr << " " << &ptr << "\n";

    *ptr = 20;
    cout << val << " " << ref << " " << *ptr << "\n";

    int another = 30;
    ptr = &another;
    *ptr = 50;
    cout << val << " " << another << " " << *ptr << "\n";

    ptr = nullptr;
    if (!ptr) cout << "NULL\n";

    return 0;
}