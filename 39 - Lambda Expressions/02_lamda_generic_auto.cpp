/**
 * @file 02_lambda_generic_auto.cpp
 * @brief Shows generic lambdas using `auto` parameters and `noexcept` specifier.
 *
 * C++14 introduced generic lambdas where parameters can be `auto`.
 * This allows the same lambda to work with different types.
 * Also demonstrates `noexcept` for exception safety.
 */

#include <iostream>
using namespace std;

int main()
{
    // Basic lambda (same as before)
    auto fsum2 = [](int x, int y)
    {
        return x + y; // Works only with int
    };

    // Generic lambda: accepts any type (C++14 feature)
    auto fsum3 = [](auto x, auto y)
    {
        return x + y; // Type deduced at call site
    };

    cout << fsum3(2, 4) << " " << fsum3(2.5, 3) << "\n"; // Output: 6 5.5

    // Generic lambda with noexcept (promises no exceptions thrown)
    auto fsum4 = [](auto x, auto y) noexcept
    {
        return x + y;
    };

    // fsum4(1, 2); // OK
    // fsum4("Hello", "World"); // Would concatenate if <string> included

    return 0;
}