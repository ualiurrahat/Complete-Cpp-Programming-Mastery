// 03_safe_division_with_optional.cpp
/**
 * @file 03_safe_division_with_optional.cpp
 * @brief Uses std::optional to safely return division results or indicate failure.
 *
 * Unlike pair<bool, T>, optional<double> clearly expresses: "I might have a double".
 * No magic values. No ambiguity. Clean, expressive, exception-free error handling.
 */

#include <iostream>
#include <optional>
using namespace std;

/**
 * @brief Safely divides two numbers.
 * @param a Numerator
 * @param b Denominator
 * @return optional<double>: contains result if b != 0, otherwise nullopt
 */
optional<double> divide2(double a, double b)
{
    if (b != 0.0)
        return a / b; // Implicit construction from value
    return {};        // Explicit nullopt
}

int main()
{
    // Successful division
    optional<double> ret = divide2(6, 3);
    if (ret)
        cout << "6 / 3 = " << *ret << endl;

    // Failed division
    ret = divide2(6, 0);
    if (!ret)
        cout << "Not possible (division by zero)" << endl;

    return 0;
}