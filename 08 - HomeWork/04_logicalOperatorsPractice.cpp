/**
 * @file 04_logicalOperatorsPractice.cpp
 * @brief Homework 1: Guess the output using logical and comparison operators.
 *
 * This program demonstrates how logical (`&&`, `||`) and comparison (`==`, `!=`, `>=`, etc.)
 * operators work together in complex expressions.
 *
 * It helps you understand **operator precedence**, **short-circuit evaluation**, and
 * how multiple relational expressions combine to form logical outcomes.
 */

#include <iostream>
using namespace std;

/**
 * @brief Entry point of the program.
 *
 * @return int Program exit status (0 = success).
 *
 * @note Demonstrates how relational and logical expressions evaluate in C++.
 */
int main()
{
    int a = 10, b = 20, c = 30, d = 40;

    // Each line prints either 1 (true) or 0 (false)
    cout << (a + b == c) << "\n";         // 10 + 20 == 30 → true
    cout << (a + b + c >= 2 * d) << "\n"; // 60 >= 80 → false

    cout << (a > 5 || d < 30) << "\n";  // true || false → true
    cout << (a > 5 && d < 30) << "\n";  // true && false → false
    cout << (a <= b && b <= c) << "\n"; // true && true → true

    cout << (a > 5 && d < 30 || c - b == 10) << "\n"; // (true && false) || true → true
    cout << (a <= b && b <= c && c <= d) << "\n";     // true && true && true → true

    cout << (a > 5 && d < 30 || c > d || d % 2 == 0) << "\n"; // (true&&false)||false||true → true
    cout << (a > 5 && d < 30 || c > d && d % 2 == 0) << "\n"; // true && false || (false && true) → false || false → false

    cout << (a == 10 || b != 20 && c != 30 || d != 40) << "\n";   // (true) || ... → true
    cout << ((a == 10 || b != 20) && c != 30 || d != 40) << "\n"; // (true && false) || false → false

    return 0;
}
