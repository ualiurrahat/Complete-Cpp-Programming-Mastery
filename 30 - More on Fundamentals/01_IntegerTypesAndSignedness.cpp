/**
 * @file 01_IntegerTypesAndSignedness.cpp
 * @brief Demonstrates signed and unsigned `int` types, size, range, and wrap-around behavior.
 *
 * Key Concepts:
 * - `int` is signed by default; `unsigned int` holds only non-negative values.
 * - Size of `int` is implementation-defined (commonly 4 bytes on 32/64-bit systems).
 * - Overflow/underflow in signed/unsigned integers follows two's complement wrapping.
 * - Use `<climits>` for portable min/max constants.
 */

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // ---------------------------------------------------------------------
    // Signed integers (default)
    // ---------------------------------------------------------------------
    int int_var1 = -10;        // Regular signed integer
    signed int int_var2 = -10; // Explicitly signed — identical to `int`

    // Display value and size (sizeof returns bytes)
    cout << int_var2 << ": " << sizeof(int_var1) << " bytes\n";

    // Print minimum and maximum for signed int
    cout << INT_MIN << " " << INT_MAX << "\n"; // e.g., -2147483648 2147483647

    // Overflow: INT_MAX + 1 wraps around to INT_MIN (two's complement)
    int_var1 = INT_MAX + 1;
    cout << "Overflow (INT_MAX + 1): " << int_var1 << "\n";

    // ---------------------------------------------------------------------
    // Unsigned integers
    // ---------------------------------------------------------------------
    unsigned int int_var3 = UINT_MAX; // Max value: 4294967295
    cout << "Unsigned int range: 0 " << int_var3 << "\n";

    ++int_var3; // Overflow: wraps to 0
    cout << "Overflow (++UINT_MAX): " << int_var3 << "\n";

    int_var3 = -1; // Negative literal → underflow (max value)
    cout << "Underflow (-1): " << int_var3 << "\n";

    int_var3 = -2; // Another underflow example
    cout << "Underflow (-2): " << int_var3 << "\n";

    return 0;
}