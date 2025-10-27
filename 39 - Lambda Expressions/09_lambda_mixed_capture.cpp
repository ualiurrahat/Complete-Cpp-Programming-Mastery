/**
 * @file 09_lambda_mixed_capture.cpp
 * @brief Advanced capture: default + explicit exceptions.
 *
 * - `[=, &c]`: all by value, except `c` by reference
 * - `[&, b]`: all by reference, except `b` by value
 *
 * Useful when most variables should be copied/referenced, but one needs special treatment.
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a = 1, b = 5, c = 20;

    // [=] default + &c: all copied except c (ref)
    [=, &c]()
    {
        c += 10; // Modifies original c
        // a += 1; // Error: a is const copy
    }();
    // c = 30

    // [&] default + b by value: all ref except b (copy)
    [&, b]() mutable
    {
        c += 10;  // c = 40
        b += 100; // Only modifies local copy
    }();
    // b still 5, c = 40

    return 0;
}