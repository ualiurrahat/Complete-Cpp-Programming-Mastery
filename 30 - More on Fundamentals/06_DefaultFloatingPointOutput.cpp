/**
 * @file 06_DefaultFloatingPointOutput.cpp
 * @brief Demonstrates default `cout` formatting for floating-point numbers.
 *
 * Default Rules:
 * - Up to **6 significant digits**
 * - Trailing `.0` is removed
 * - Switches to scientific notation for very large/small numbers
 * - Actual stored values may differ from printed ones due to binary representation
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << 5.0 << '\n'; // 5
    cout << 6.7 << '\n'; // 6.7

    double a = 0.1;
    double b = 1.0 / 3.0;

    cout << fixed << setprecision(20);
    cout << a << "\n"; // 0.10000000000000000555 → not exactly 0.1
    cout << b << "\n"; // 0.33333333333333331483 → not exactly 1/3

    return 0;
}