/**
 * @file 10_FloatingPointPrecisionLimits.cpp
 * @brief Demonstrates precision limits of `float`, `double`, and `long double`.
 *
 * Key Concepts:
 * - `float`: ~7 significant digits
 * - `double`: ~15–17 significant digits
 * - `long double`: platform-dependent (often 18–20)
 * - Values beyond precision are **rounded** or **lost**
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Set fixed notation and high precision to reveal internal representation
    cout << fixed << setprecision(19);

    // --- Precision comparison with repeating 3.333... ---
    cout << "Precision of floating types:\n";
    cout << 3.33333333333333333333333333333333333333f << "\n"; // float:  ~7 digits accurate
    cout << 3.33333333333333333333333333333333333333 << "\n";  // double: ~15–17 digits
    cout << 3.33333333333333333333333333333333333333L << "\n"; // long double: more

    // --- float cannot represent large integers exactly ---
    float f1 = 2147483648.0f;                         // 2^31 → 11 digits → beyond float precision
    cout << "\nfloat(2147483648.0f): " << f1 << "\n"; // May print exactly or rounded

    float f2 = 123456789.0f;                       // 9 digits → float has only ~7 → rounding occurs
    cout << "float(123456789.0f): " << f2 << "\n"; // 123456792

    double d = 123456789.0;                       // double can represent this exactly
    cout << "double(123456789.0): " << d << "\n"; // 123456789.000...

    return 0;
}