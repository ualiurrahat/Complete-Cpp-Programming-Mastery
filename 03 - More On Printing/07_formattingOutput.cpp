/**
 * @file 07_formattingOutput.cpp
 * @brief Demonstrates advanced output formatting in C++ using <iomanip>.
 *
 * Key Notes:
 * - The modulus operator (%) does not work on floating-point numbers.
 * - Unlike C, C++ does not automatically display precision for float/double.
 * - To control formatting, we use I/O manipulators from <iomanip>.
 *
 * Manipulators covered:
 * 1. showpoint / noshowpoint:
 *    - showpoint: Always shows decimal point and trailing zeros.
 *    - noshowpoint: Suppresses trailing zeros (default behavior).
 *
 * 2. setprecision(n):
 *    - Controls the total number of significant digits displayed.
 *    - Requires <iomanip>.
 *    - Example: setprecision(10) → total 10 digits (integer + fractional).
 *
 * 3. fixed:
 *    - Works with setprecision().
 *    - Makes precision apply only to digits after the decimal point.
 *
 * 4. setw(n):
 *    - Sets field width for next output (helps with alignment).
 *
 * Example:
 * cout << fixed << setprecision(5);
 * → prints exactly 5 digits after the decimal point.
 */

#include <iostream>
#include <iomanip> // Required for formatting manipulators
using namespace std;

int main()
{
    double a, b;
    double sum, mul, div, sub;

    cout << "Enter two numbers (a and b): ";
    cin >> a >> b;

    // Basic arithmetic operations
    sum = a + b;
    sub = a - b;
    mul = a * b;
    div = a / b; // Division gives decimal precision

    // Default printing
    cout << "\n--- Default Output ---\n";
    cout << "sum = " << sum << endl;
    cout << "sub = " << sub << endl;
    cout << "mul = " << mul << endl;
    cout << "div = " << div << endl;

    // Using showpoint
    cout << "\n--- Using showpoint ---\n";
    cout << showpoint; // Forces display of decimal and trailing zeros
    cout << "sum = " << sum << endl;
    cout << "sub = " << sub << endl;
    cout << "mul = " << mul << endl;
    cout << "div = " << div << endl;

    // Using noshowpoint on selected variables
    cout << "\n--- Using noshowpoint on sub and mul ---\n";
    cout << "sum = " << sum << endl;

    cout << noshowpoint; // Suppresses trailing zeros
    cout << "sub = " << sub << endl;
    cout << "mul = " << mul << endl;

    cout << showpoint; // Re-enable showpoint for consistency
    cout << "div = " << div << endl;

    // Using setprecision
    cout << "\n--- Using setprecision(10) ---\n";
    cout << setprecision(10); // Total of 10 significant digits
    cout << "sum = " << sum << endl;
    cout << "sub = " << sub << endl;
    cout << "mul = " << mul << endl;
    cout << "div = " << div << endl;

    // Using fixed with setprecision
    cout << "\n--- Using fixed with setprecision(3) ---\n";
    cout << fixed << setprecision(3); // 3 digits after decimal point
    cout << "sum = " << sum << endl;
    cout << "sub = " << sub << endl;
    cout << "mul = " << mul << endl;
    cout << "div = " << div << endl;

    // Using setw for alignment
    cout << "\n--- Using setw() for alignment ---\n";
    cout << setw(15) << "sum = " << sum << endl;
    cout << "sub = " << sub << endl;
    cout << setw(25) << "mul = " << mul << endl;
    cout << "div = " << div << endl;

    return 0;
}
