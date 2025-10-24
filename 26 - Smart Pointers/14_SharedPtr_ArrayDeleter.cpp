/**
 * @file 14_SharedPtr_ArrayDeleter.cpp
 * @brief `shared_ptr` with arrays — custom deleter required.
 *
 * Problem Statement:
 * `shared_ptr<T[]>` not allowed pre-C++17 → use deleter.
 *
 * New Topics Introduced:
 * - `delete[]` via lambda
 * - Template deleter for reuse
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <memory>
using namespace std;

int main() {
    shared_ptr<int> p(new int[10], [](int* arr) {
        cout << "Array deleted\n";
        delete[] arr;
    });

    // p[0] = 5;  // ERROR: no operator[]
    // Use raw pointer or switch to unique_ptr<int[]>

    return 0;
}