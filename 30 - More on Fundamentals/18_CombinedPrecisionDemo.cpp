/**
 * @file 18_CombinedPrecisionDemo.cpp
 * @brief Combines all floating-point precision demos into one file.
 *
 * Shows:
 * - Literal suffixes
 * - Precision loss in `float`
 * - Exact representation in `double`
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << fixed << setprecision(19);

    cout << 3.333333333333333333f << "\n"; // float
    cout << 3.333333333333333333 << "\n";  // double
    cout << 3.333333333333333333L << "\n"; // long double

    float f1 = 2147483648.0f;
    float f2 = 123456789.0f;
    double d = 123456789.0;

    cout << f1 << "\n";
    cout << f2 << "\n";
    cout << d << "\n";

    return 0;
}