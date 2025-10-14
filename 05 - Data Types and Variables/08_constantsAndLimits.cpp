/**
 * @file 08_constantsAndLimits.cpp
 * @brief Demonstrates constants in C++ and using limits from <climits>.
 *
 * @details
 * - Constants: variables whose values cannot be changed after initialization.
 *   - Use `const` keyword.
 *   - Naming convention: usually uppercase letters.
 * - C++ limits: maximum and minimum values for data types using <climits>.
 */

#include <iostream>
#include <climits> // For INT_MAX, INT_MIN
using namespace std;

int main()
{
    // Constant double (cannot be changed later)
    const double PI = 3.14159;
    // PI = 10; // ERROR: Cannot modify a const variable

    // Constant int
    const int LUCKY{13};
    // const int x; // ERROR: must initialize const variables

    // Constant char
    const char charVal = 'A';

    // Constant string
    const string str = "Welcome to our BANK";

    // Display C++ integer limits
    cout << "Maximum int value: " << INT_MAX << "\n"; // 2147483647
    cout << "Minimum int value: " << INT_MIN << "\n"; // -2147483648

    return 0;
}
