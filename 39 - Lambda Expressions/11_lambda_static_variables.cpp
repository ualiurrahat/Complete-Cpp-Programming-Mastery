/**
 * @file 11_lambda_static_variables.cpp
 * @brief Lambdas can access static variables without capture.
 *
 * Static variables have static storage duration → always accessible.
 * No need to capture them.
 * Local non-static variables must be captured.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int x = 0;
    static int y = 0;

    // Lambda with 'mutable' to allow internal state
    auto f = []() mutable
    {
        // ++x; // Compilation Error: x not captured
        ++y; // OK: static variables are accessible
    };

    f(), f(), f();     // y incremented 3 times
    cout << y << "\n"; // Output: 3

    return 0;
}