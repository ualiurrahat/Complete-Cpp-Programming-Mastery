/**
 * @file 02_MainWithHeader.cpp
 * @brief Use function from external header file.
 *
 * Problem Statement:
 * Include and use `sum_1_n()` from `sum.h`.
 *
 * New Topics Introduced:
 * - `#include "sum.h"` → user-defined header
 * - Header must be in same directory or include path
 * - **No redefinition** if included once
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include "sum.h"  // Custom header
using namespace std;

int main() {
    cout << sum_1_n(5) << "\n";  // 10
    return 0;
}