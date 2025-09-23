/**
 * @file 09_constant.cpp
 * @brief Demonstrates constant variables in C++
 *
 * -----------------------------
 * 📘 Constant Variables:
 * -----------------------------
 * - Declared using the `const` keyword.
 * - Value cannot be modified after initialization.
 * - Ensures data safety, prevents accidental modification.
 *
 * -----------------------------
 * 🔹 Common Use Cases:
 * -----------------------------
 * - Defining fixed values (like PI = 3.14159).
 * - Used in array sizes, loop limits, configuration values.
 */

#include <iostream>
using namespace std;

int main()
{
    const int a = 4; // a is read-only
    cout << "The value of a is: " << a << endl;

    // a = 5;  // ❌ Error: assignment of read-only variable
    return 0;
}
