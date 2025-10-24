/**
 * @file 14_RangeBasedLoopRef.cpp
 * @brief Using references in range-based for loops.
 *
 * Problem Statement:
 * Modify vector elements using `auto&` in range-based loop.
 *
 * New Topics Introduced:
 * - `for (auto &val : container)` → modify original
 * - `for (auto val : container)` → copy, no modification
 *
 * @note Time Complexity: O(n)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec{1, 2, 3, 4};

    for (auto &val : vec) {
        cout << val << " ";
        val = 1;
    }
    cout << "\n";

    for (auto &val : vec)
        cout << val << " ";
    cout << "\n";  // 1 1 1 1

    return 0;
}