/**
 * @file 04_printingDifferentTypes.cpp
 * @brief Shows printing of integers, floating-point numbers and strings.
 *
 * @details
 * Demonstrates:
 *  - How cout prints numbers (integers & float) and strings.
 *  - String literals vs numeric literals ("123" vs 123).
 *  - Using '\n' and endl.
 *
 * Problem statement:
 * - Print several values of different types and show basic concatenation.
 *
 * Expected output (approx):
 * 1
 * 12
 * 123 is a number
 * 123 is NOT a number
 *
 * 15.7
 * -12.52
 *
 * 1234
 * 4321
 *
 * 43211234
 * 43211234
 *
 * My luck number is: 25
 *
 * Note: actual arrangement depends on the platform's console width,
 * but line breaks shown here will be respected.
 *
 * @note Time complexity: O(1)
 * @note Space complexity: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    cout << 1 << "\n";
    cout << 12 << "\n";
    cout << 123 << " is a number\n";       // numeric literal printed as number
    cout << "123" << " is NOT a number\n"; // string literal printed as text
    cout << endl;

    cout << 15.7 << "\n";
    cout << -12.52 << "\n";
    cout << endl;

    cout << 1234 << "\n";
    cout << 4321 << "\n\n";

    // Note: printing two integers back-to-back without separators concatenates their
    // textual representations in the output stream, not numerical addition:
    cout << 43211234 << "\n";
    cout << 4321 << 1234 << "\n"; // prints "43211234" because no separator between values

    cout << "\nMy luck number is: " << 25 << "\n";

    return 0;
}
