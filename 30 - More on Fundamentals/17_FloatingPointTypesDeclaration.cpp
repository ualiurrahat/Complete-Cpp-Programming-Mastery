/**
 * @file 17_FloatingPointTypesDeclaration.cpp
 * @brief Proper declaration syntax for `float`, `double`, `long double`.
 *
 * Suffixes:
 * - No suffix → `double`
 * - `f` or `F` → `float`
 * - `L` → `long double`
 *
 * Recommendation:
 * - Use `double` by default
 * - Use `float` only for memory (e.g., graphics, ML)
 * - `long double` rarely needed
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double x = 10.0;       // default
    float y = 20.0f;       // explicit float
    long double z = 22.4L; // long double

    cout << fixed << setprecision(19);
    cout << x << "\n";
    cout << y << "\n";
    cout << z << "\n";

    return 0;
}