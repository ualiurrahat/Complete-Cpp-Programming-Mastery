/**
 * @file 07_ScientificAndFixedNotation.cpp
 * @brief Controls output format using `scientific`, `fixed`, and `setprecision`.
 *
 * Manipulators:
 * - `scientific`: Force `e+xx` notation
 * - `fixed`: Force decimal format with exact digits after point
 * - `setprecision(n)`:
 *     - In `scientific`: total significant digits
 *     - In `fixed`: digits after decimal
 * - `showpoint`: Always show decimal point
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << 6.7 << '\n';        // 6.7
    cout << 9876543.21 << '\n'; // 9.87654e+06

    cout.setf(ios::scientific);
    cout << 6.7 << '\n';        // 6.700000e+00
    cout << 9876543.21 << '\n'; // 9.876543e+06

    cout << 0.0000000008 << '\n'; // 8.000000e-10
    cout << 146000.001 << "\n";   // 1.460000e+05

    cout.precision(10);
    cout << 146000.001 << "\n"; // 1.4600000100e+05

    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);

    cout << 146000.001 << "\n"; // 146000.0010000000
    cout << 100.0 << "\n";      // 100.0000000000

    return 0;
}