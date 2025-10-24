/**
 * @file 02_PointerToPointer.cpp
 * @brief Multi-level indirection: pointer to pointer.
 *
 * Problem Statement:
 * Trace memory addresses through multiple pointer levels.
 *
 * New Topics Introduced:
 * - `int**` → pointer to `int*`
 * - `***ptr` → value at final address
 * - Chain: `var → ptr1 → ptr2 → ptr3`
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int var = 10;
    int* ptr1 = &var;
    int** ptr2 = &ptr1;
    int*** ptr3 = &ptr2;

    cout << &var << " " << var << "\n";
    cout << &ptr1 << " " << ptr1 << " " << *ptr1 << "\n";
    cout << &ptr2 << " " << ptr2 << " " << *ptr2 << " " << **ptr2 << "\n";
    cout << &ptr3 << " " << ptr3 << " " << *ptr3 << " " << **ptr3 << " " << ***ptr3 << "\n";

    return 0;
}