/**
 * @file 14_lambda_variadic_fold_expressions.cpp
 * @brief C++17 variadic lambdas with fold expressions.
 *
 * `auto... args` → parameter pack
 * `(expr, ...)` → fold expression (comma operator)
 *
 * Enables elegant handling of variable number of arguments.
 * Common in generic logging, printing, etc.
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

// Variadic function using fold expression
void Print1(auto... args)
{
    ((cout << args << ' '), ...);
    cout << '\n';
    // Fold expands left-to-right:
    // (((cout << 10 << ' '), (cout << 20 << ' ')), (cout << 30 << ' '))
}

// Variadic lambda with per-element processing
void LambdaPrint(auto... args)
{
    // Inner lambda: decorates each argument
    auto PrintElement = [](const auto &x)
    {
        ostringstream oss;
        oss << "[[[{" << x << "}]]]";
        cout << oss.str() << " ";
    };

    (PrintElement(args), ...); // Apply to each arg
    cout << '\n';
}

// Capture entire parameter pack
void CaptureArgsInLambda(auto... args)
{
    // args... becomes captured pack
    auto f = [args...]()
    {
        int sz = sizeof...(args);
        cout << sz << "\n";
    };
    f();
}

int main()
{
    // Variadic lambda defined and stored
    auto lambda = [](auto... args)
    {
        ((cout << args << ' '), ...);
        cout << '\n';
    };

    lambda(1, 2, 3); // Output: 1 2 3

    Print1(10, 20, 30); // Output: 10 20 30
    LambdaPrint(5, "hi", 3.14);
    // Output: [[[{5}]]] [[[{hi}]]] [[[{3.14}]]]

    CaptureArgsInLambda(1, "test", 'A'); // Output: 3

    return 0;
}