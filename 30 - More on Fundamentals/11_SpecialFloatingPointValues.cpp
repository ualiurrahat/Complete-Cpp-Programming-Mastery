/**
 * @file 11_SpecialFloatingPointValues.cpp
 * @brief Shows IEEE 754 special values: Infinity and NaN.
 *
 * Intuition:
 * - `+inf` = 5.0 / 0.0
 * - `-inf` = -5.0 / 0.0
 * - `NaN` = 0.0 / 0.0 (undefined)
 * - `NaN == NaN` is **always false** — by design!
 */

#include <iostream>
using namespace std;

int main()
{
    double zero = 0.0;

    // Positive infinity
    double posinf = 5.0 / zero;
    cout << "5.0 / 0.0 = " << posinf << "\n"; // inf

    // Negative infinity
    double neginf = -5.0 / zero;
    cout << "-5.0 / 0.0 = " << neginf << "\n"; // -inf

    // Not a Number (NaN)
    double nan = zero / zero;
    cout << "0.0 / 0.0 = " << nan << "\n"; // nan or -nan

    // NaN is NEVER equal to itself
    if (nan == nan)
        cout << "This will NOT print!\n";
    else
        cout << "NaN != NaN → true by IEEE 754\n";

    return 0;
}