/**
 * @file 04_operatorPrecedence.cpp
 * @brief Demonstrates how operator precedence affects calculation in int and double.
 *
 * @details
 * - / and * have higher precedence than +
 * - Parentheses () can change the order of evaluation
 * - Demonstrates difference between integer and floating point operations
 */

#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 21;

    int i1 = a + b / 2;   // 10 + (21 / 2) = 10 + 10 = 20
    int i2 = (a + b) / 2; // (10 + 21) / 2 = 31 / 2 = 15

    double x = 10.0;
    double y = 21.0;

    double d1 = x + y / 2.0;   // 10.0 + (21.0 / 2.0) = 10 + 10.5 = 20.5
    double d2 = (x + y) / 2.0; // (10 + 21) / 2 = 31 / 2 = 15.5

    // Optional: print to see results
    cout << "i1 = " << i1 << ", i2 = " << i2 << "\n";
    cout << "d1 = " << d1 << ", d2 = " << d2 << "\n";

    return 0;
}
