// <DOCUMENT filename="08_ExceptionHandling.cpp">
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
using namespace std;

/**
 * @file 08_ExceptionHandling.cpp
 * @brief Comprehensive exception handling with standard exceptions.
 *
 * Covers:
 * - Throwing standard exceptions (`domain_error`, `out_of_range`)
 * - Catching by reference (`&`)
 * - Exception hierarchy: `logic_error` → `domain_error`, `out_of_range`
 * - What NOT to catch: division by zero (undefined behavior)
 *
 * Source Inspiration: Weiss C++ Exception Demo
 */

void div(int x)
{
    // No exception on divide by zero — undefined behavior!
    // Handled by hardware/OS, not C++ exceptions
    100000 / x;
}

void array_access(int pos)
{
    vector<int> v(5);
    // .at() throws out_of_range if pos >= size
    v.at(pos) = 1;
}

double mysqrt(double x)
{
    if (x < 0)
        throw domain_error("sqrt of neg number");
    else
        return sqrt(x);
}

double myexp(double x)
{
    double result = exp(x);
    if (result == HUGE_VAL || result != result) // Also catch NaN
        throw out_of_range("exp too large");
    else
        return result;
}

void test(double x)
{
    try
    {
        mysqrt(x);
        myexp(x);
        array_access(static_cast<int>(x));
    }
    catch (const domain_error &e)
    {
        cout << "Caught DOMAIN exception: " << e.what() << endl;
    }
    catch (const logic_error &e)
    {
        cout << "Caught logical error: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Caught unknown exception\n";
    }
}

int main()
{
    cout << "test(10):\n";
    test(10); // All good
    cout << "\ntest(-4):\n";
    test(-4); // domain_error
    cout << "\ntest(1e7):\n";
    test(10000000); // out_of_range
    cout << "\ntest(0):\n";
    test(0); // CRASH: div by zero

    return 0;
}