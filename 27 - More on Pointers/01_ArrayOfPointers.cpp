/**
 * @file 01_ArrayOfPointers.cpp
 * @brief Array of pointers — each element points to a variable.
 *
 * Problem Statement:
 * Store addresses of multiple variables in an array.
 *
 * New Topics Introduced:
 * - `int* arr[3]` → array of 3 pointers
 * - Each `arr[i]` holds address of an `int`
 * - Memory layout: variables vs pointers
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20, c = 50;
    int* arrop[3] = {&a, &b, &c};

    cout << &a << " " << &b << " " << &c << "\n";
    for (int i = 0; i < 3; ++i)
        cout << &arrop[i] << " " << arrop[i] << " " << *arrop[i] << "\n";

    return 0;
}