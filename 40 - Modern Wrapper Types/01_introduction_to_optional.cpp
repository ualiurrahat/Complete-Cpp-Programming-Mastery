// 01_introduction_to_optional.cpp
/**
 * @file 01_introduction_to_optional.cpp
 * @brief Demonstrates the need for std::optional by comparing traditional error-handling patterns.
 *
 * Before C++17, functions returning values had to use sentinel values, pairs, or pointers
 * to indicate failure. This example shows a division function using pair<bool, double>
 * and a processing function using default parameters as flags — both are error-prone.
 * std::optional solves this cleanly by wrapping a value that may or may not exist.
 */

#include <iostream>
#include <utility>
using namespace std;

/**
 * @brief Divides two numbers and returns success flag with result.
 * @param a Numerator
 * @param b Denominator
 * @return Pair: {true, result} on success; {false, 0} on failure
 *
 * This is a classic pre-optional pattern. It works but is verbose and unsafe
 * (caller might ignore the bool). Also, returning 0 on failure is ambiguous
 * if 0 is a valid result.
 */
pair<bool, double> divide1(double a, double b)
{
    if (b != 0.0)
        return {true, a / b};
    return {false, 0};
}

/**
 * @brief Processes input using default arguments as error indicators.
 * @param val Input value (-1 means not provided)
 * @param p Pointer to additional data (nullptr means not provided)
 * @return Computed result or -1 if nothing to process
 *
 * Using magic values (-1, nullptr) as flags is common but fragile.
 * Callers can easily misuse or forget to check.
 */
int process(int val = -1, int *p = nullptr)
{
    if (val == -1 && p == nullptr)
        return -1; // Special value indicating "cannot process"

    int ret = 0;
    if (val != -1)
        ret += 2 * val + 1;
    if (p != nullptr)
        ret += 3 + *p;
    return ret;
}

int main()
{
    // -------------------------------------------------
    // Example: Using divide1 (C++11/14 compatible)
    // -------------------------------------------------
    // std::tie creates a tuple of references and unpacks the pair
    bool success;
    double result;
    std::tie(success, result) = divide1(10, 2);

    if (success)
        cout << "10 / 2 = " << result << endl;
    else
        cout << "Division failed!" << endl;

    // -------------------------------------------------
    // Alternative: Direct access (even simpler)
    // -------------------------------------------------
    // pair<bool, double> res = divide1(10, 2);
    // if (res.first)
    //     cout << "10 / 2 = " << res.second << endl;
    // else
    //     cout << "Division failed!" << endl;

    // -------------------------------------------------
    // Example: Using process
    // -------------------------------------------------
    int x = 5;
    cout << "process(3, &x) = " << process(3, &x) << endl;
    cout << "process() = " << process() << endl;

    return 0;
}