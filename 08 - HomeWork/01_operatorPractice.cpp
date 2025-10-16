/**
 * @file 01_operatorPractice.cpp
 * @brief Demonstrates complex usage of increment, arithmetic, and assignment operators.
 *
 * This program tests how prefix and postfix increment operators interact with
 * arithmetic and compound assignment expressions in C++.
 */

#include <iostream>
using namespace std;

int main()
{
    // Initialize variables
    int a = 0, b = 1;

    // Postfix increment: prints then increments
    cout << a++ << "\n"; // Prints 0, then a becomes 1

    // Prefix increment: increments first, then prints
    cout << ++a << "\n"; // a = 2, prints 2

    // Compound arithmetic and assignment
    a += 2 * b + 1;                // a = 2 + (2*1 + 1) = 5
    b = ++a * 2;                   // a becomes 6, b = 6 * 2 = 12
    cout << a << " " << b << "\n"; // 6 12

    // Demonstrating operator precedence
    b = a;                      // b = 6
    a = 12 + a / 3 / 2 - 2 * 2; // a = 12 + (6/3)/2 - 4 = 12 + 1 - 4 = 9
    cout << a << "\n";          // Prints 9

    // Resetting and reusing variables in complex expression
    a = b;                          // a = 6
    a = ((12 + a) / 3 / 2 - 2) * 2; // a = ((18)/3/2 - 2)*2 = (3 - 2)*2 = 2
    cout << a << "\n";              // Prints 2

    return 0;
}
