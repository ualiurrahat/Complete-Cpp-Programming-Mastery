/**
 * @file 16_Nullptr.cpp
 * @brief Safe null pointer initialization using `nullptr`.
 *
 * Problem Statement:
 * Show modern C++ way to represent null pointers.
 *
 * New Topics Introduced:
 * - `nullptr` → type-safe null
 * - Avoid `NULL` (macro) and `0`
 * - Prevent accidental integer assignment
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    double x = 10;
    double *ptr1 = &x;
    double *ptr2 = nullptr;  // Preferred
    double *ptr3 = 0;        // OK, but old
    // double *ptr4;         // Dangling! Avoid

    return 0;
}