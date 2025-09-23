/**
 * @file 08_referenceVariable.cpp
 * @brief Demonstrates reference variables in C++
 *
 * -----------------------------
 * 📘 Reference Variable:
 * -----------------------------
 * - A reference variable is an alias (another name) for an existing variable.
 * - Unlike pointers, references:
 *      1. Must be initialized when declared.
 *      2. Cannot be null.
 *      3. Cannot be reseated (always refers to the same variable).
 *
 * -----------------------------
 * 🔹 Why use references?
 * -----------------------------
 * - Simplifies function parameter passing.
 * - Used in operator overloading.
 * - Efficient, as no copy of the variable is created.
 */

#include <iostream>
using namespace std;

int main()
{
    int x = 8;  // Original variable
    int &y = x; // Reference variable (y is just another name for x)

    // Changing y will also change x, since they both refer to the same memory location
    cout << "Value of x: " << x << endl;
    cout << "Value of y (reference to x): " << y << endl;

    return 0;
}
