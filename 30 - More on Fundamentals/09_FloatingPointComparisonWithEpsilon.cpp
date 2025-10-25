/**
 * @file 09_FloatingPointComparisonWithEpsilon.cpp
 * @brief Safe floating-point comparison using epsilon tolerance.
 *
 * Why `==` fails:
 *   `0.1 + 0.1 + ...` ≠ `1.0` due to binary rounding errors.
 *
 * Solution:
 *   Compare `|a - b| <= EPS` where `EPS` is small (e.g., 1e-10).
 *
 * Also shows precision differences between `float`, `double`, `long double`.
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/**
 * @brief Compare two doubles with tolerance.
 * @param a First value
 * @param b Second value
 * @param EPS Maximum allowed difference (default: 1e-10)
 * @return -1 if a < b, 0 if equal within EPS, 1 if a > b
 */
int dcmp(double a, double b, double EPS = 1e-10)
{
    if (fabs(a - b) <= EPS)
        return 0;
    return (a < b) ? -1 : 1;
}

int main()
{
    double a = 3.0 / 7.0;
    double b = 0.1 + 3.0 / 7.0 - 0.1;

    cout << boolalpha;
    cout << (a == b) << "\n";          // false
    cout << (dcmp(a, b) == 0) << "\n"; // true

    cout << (dcmp(1.0 / 3.0, 0.33333333333333) == 0) << "\n";  // true
    cout << (dcmp(1.0 / 3.0, 0.333333333) == 0) << "\n";       // false
    cout << (dcmp(1.0 / 3.0, 0.333333333, 1e-9) == 0) << "\n"; // true

    cout << "\nPrecision of floating types:\n";
    cout << fixed << setprecision(20);

    cout << 3.333333333333333333f << "\n"; // float
    cout << 3.333333333333333333 << "\n";  // double
    cout << 3.333333333333333333L << "\n"; // long double

    cout << "\nFloat rounding error:\n";
    cout << setprecision(9);
    float f = 123456789.0f;
    cout << f << "\n"; // 123456792 → only ~7 significant digits

    return 0;
}