/**
 * @file 01_pointer.cpp
 * @brief Demonstrates the concept of pointers in C++.
 *
 * A pointer is a variable that stores the memory address of another variable.
 * - `&` (address-of operator) is used to get the memory address.
 * - `*` (dereference operator) is used to access the value stored at an address.
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    int a = 4;

    // Pointer declaration: b stores the address of a
    int *b = &a;

    cout << "Value of a: " << a << endl;    // prints value of a
    cout << "Address of a: " << &a << endl; // prints memory address of a
    cout << "Value of b (address of a): " << b << endl;
    cout << "Dereferencing b (*b): " << *b << endl; // prints value stored at address b points to

    return 0;
}
