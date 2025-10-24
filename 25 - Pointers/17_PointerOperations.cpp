/**
 * @file 17_PointerOperations.cpp
 * @brief Pointer assignment, swapping, and type safety.
 *
 * Problem Statement:
 * Demonstrate pointer reassignment, swapping, and type mismatch.
 *
 * New Topics Introduced:
 * - Pointers can be reassigned
 * - `swap(p1, p2)` swaps pointer values
 * - Type safety: `int*` ≠ `double*`
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int val1 = 5, val2 = 15;
    int *p1 = &val1, *p2 = &val2;

    *p1 = 10;
    *p2 = *p1 + 6;
    cout << val1 << " " << val2 << "\n";  // 10 16

    p1 = p2;
    *p1 = 20;
    cout << val1 << " " << val2 << "\n";  // 10 20

    p1 = &val1;
    swap(p1, p2);
    cout << *p1 << " " << *p2 << "\n";  // 20 10

    // double x = 10;
    // p1 = &x;  // ERROR: type mismatch

    return 0;
}