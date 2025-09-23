/**
 * @file 02_pointerToPointer.cpp
 * @brief Demonstrates pointer-to-pointer (double pointers).
 *
 * A double pointer (**c) stores the address of another pointer.
 * This allows multi-level indirection in memory referencing.
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    int a = 4;
    int *b = &a;  // b stores address of a
    int **c = &b; // c stores address of b (double pointer)

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;

    cout << "Value of b (address of a): " << b << endl;
    cout << "Dereferencing b (*b): " << *b << endl;

    cout << "Address of b: " << &b << endl;
    cout << "Value of c (address of b): " << c << endl;
    cout << "Dereferencing c (*c): " << *c << endl;        // address of a
    cout << "Double dereferencing (**c): " << **c << endl; // value of a

    return 0;
}
