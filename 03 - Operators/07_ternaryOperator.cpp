/**
 * @file 07_ternaryOperator.cpp
 * @brief Demonstrates the use of the ternary (?:) operator in C++.
 *
 * The ternary operator is a shorthand for `if-else` conditions.
 * Syntax: condition ? expression_if_true : expression_if_false;
 *
 * Example: (a > b) ? a : b;  // returns the larger of a and b
 */

#include <iostream>
using namespace std;

int main()
{
    int num1, num2;

    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    // Using ternary operator to determine the larger number
    int large = (num1 > num2) ? num1 : num2;

    cout << "The larger number is: " << large << endl;

    return 0;
}

/**
 * Example Run:
 * Input: 10 25
 * Output: The larger number is: 25
 */
