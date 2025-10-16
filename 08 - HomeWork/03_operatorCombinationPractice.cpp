/**
 * @file 03_operatorCombinationPractice.cpp
 * @brief Demonstrates division, arithmetic, and increment/decrement combinations.
 *
 * This example explores how operator precedence and order of execution
 * affect expressions in C++.
 *
 * ⚠️ Warning:
 *   Some statements are syntactically valid but considered bad practice,
 *   such as mixing pre/post increments in a single expression or writing `++a += 10`.
 */

#include <iostream>
using namespace std;

int main()
{
    int a = 210;

    // Sequential divisions
    a /= 2; // a = 105
    cout << a << "\n";

    cout << (a /= 3) << "\n"; // a = 35
    cout << (a /= 5) << "\n"; // a = 7
    cout << (a /= 7) << "\n"; // a = 1

    // Demonstrating operator precedence and parentheses
    cout << (2 + 3) * (5 - (-3)) / 5 / 8 << "\n"; // (5 * 8) / 40 = 1

    // Demonstrating prefix and postfix increment combinations
    a = 10;
    cout << a++ + 10 << "\n"; // 10 + 10 = 20, then a becomes 11
    cout << ++a + 10 << "\n"; // a = 12 -> prints 22
    cout << a-- + 10 << "\n"; // prints 22, then a becomes 11
    cout << --a + 10 << "\n"; // a = 10 -> prints 20

    int b = 20;
    cout << a++ + ++b << "\n"; // Undefined behavior (don’t code this way!)

    cout << a << "\n"; // Current value of a after above ops

    // The following line is syntactically valid but BAD practice.
    // Explanation:
    //   (++a) increments a first, making it an lvalue.
    //   Then the result is incremented by 10.
    ++a += 10; // BAD practice! Avoid in real programs.
    cout << a << "\n";

    return 0;
}
