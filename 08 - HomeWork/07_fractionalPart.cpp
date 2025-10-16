/**
 * @file 07_fractionalPart.cpp
 * @brief Display the fractional part of a division between two numbers.
 *
 * Problem Statement:
 * Given two floating-point numbers `a` and `b`,
 * compute the fractional part of the division (a / b).
 */

#include <iostream>
using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;

    double result = a / b;

    // Fractional part = value - its integer part
    cout << result - static_cast<int>(result);

    return 0;
}
