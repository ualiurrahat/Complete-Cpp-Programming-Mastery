/**
 * @file 05_UniquePtr_Return.cpp
 * @brief Return `unique_ptr` from functions — move semantics.
 *
 * Problem Statement:
 * Efficiently return dynamically allocated objects.
 *
 * New Topics Introduced:
 * - Return by value → **move** (no copy)
 * - RVO/NRVO may optimize further
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <memory>
using namespace std;

unique_ptr<int> create_int() {
    return make_unique<int>(20);  // Moved out
}

int main() {
    auto p = create_int();  // Efficient move
    cout << *p << "\n";     // 20
    return 0;
}