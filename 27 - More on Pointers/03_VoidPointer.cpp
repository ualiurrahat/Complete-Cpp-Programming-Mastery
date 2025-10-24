/**
 * @file 03_VoidPointer.cpp
 * @brief `void*` — generic pointer for any type.
 *
 * Problem Statement:
 * Store pointer without knowing type; cast back to use.
 *
 * New Topics Introduced:
 * - `void*` can point to any data
 * - Must cast to correct type before dereferencing
 * - Used in C APIs, memory functions
 *
 * @warning Never dereference `void*` directly
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int x = 10;
    double y = 20.5;
    void* ptr = nullptr;

    ptr = &x;
    cout << *(int*)ptr << "\n";  // 10

    ptr = &y;
    cout << *(double*)ptr << "\n";  // 20.5

    return 0;
}