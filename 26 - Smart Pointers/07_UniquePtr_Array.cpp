/**
 * @file 07_UniquePtr_Array.cpp
 * @brief `unique_ptr<T[]>` for dynamic arrays.
 *
 * Problem Statement:
 * Safely manage dynamic arrays with RAII.
 *
 * New Topics Introduced:
 * - `unique_ptr<int[]>`
 * - `make_unique<int[]>(n)` → zero-initialized
 * - `p[i]` syntax works
 *
 * @note Time Complexity: O(n) for init
 * @note Space Complexity: O(n)
 */

#include <iostream>
#include <memory>
using namespace std;

int main() {
    auto arr = make_unique<int[]>(5);  // {0,0,0,0,0}
    for (int i = 0; i < 5; ++i)
        arr[i] = i + 1;

    for (int i = 0; i < 5; ++i)
        cout << arr[i] << " ";  // 1 2 3 4 5
    cout << "\n";

    return 0;
}