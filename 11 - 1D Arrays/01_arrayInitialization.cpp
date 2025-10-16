/**
 * Problem: Demonstrate different ways to initialize arrays in C++.
 *
 * Concepts:
 * - Single element initialization
 * - Partial initialization (rest elements default to 0)
 * - C++11 brace initialization
 * - Auto-sized array
 */

#include <iostream>
using namespace std;

int main()
{
    int val1 = 100; // Traditional assignment
    int val2{100};  // C++11 brace initialization

    // Array of 100 integers: first element 5, rest default to 0
    int arr1[100] = {5}; // C style
    int arr2[100]{5};    // C++11 initialization list

    // Auto-sized array (size determined by number of elements)
    int arr3[]{1, 2, 3};

    // Demonstrate accessing first and last elements
    cout << "arr1[0]: " << arr1[0] << ", arr1[1]: " << arr1[1] << "\n";
    cout << "arr2[0]: " << arr2[0] << ", arr2[1]: " << arr2[1] << "\n";
    cout << "arr3 size: " << sizeof(arr3) / sizeof(arr3[0]) << "\n";

    return 0;
}
