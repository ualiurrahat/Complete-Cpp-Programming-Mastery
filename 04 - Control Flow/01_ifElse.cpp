/**
 * @file 01_ifElse.cpp
 * @brief Demonstrates the use of if-else statements in C++.
 *
 * The if-else statement allows conditional execution of code blocks.
 * It checks whether a condition is true or false and executes the appropriate block.
 *
 * Syntax:
 * if (condition) {
 *      // executes if condition is true
 * } else {
 *      // executes if condition is false
 * }
 */

#include <iostream>
using namespace std;

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (number > 0)
    {
        cout << "The number is positive." << endl;
    }
    else if (number < 0)
    {
        cout << "The number is negative." << endl;
    }
    else
    {
        cout << "The number is zero." << endl;
    }

    return 0;
}
