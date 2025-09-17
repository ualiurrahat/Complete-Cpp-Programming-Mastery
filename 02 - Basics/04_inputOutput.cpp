/**
 * @file 04_inputOutput.cpp
 * @brief Demonstrates user input and output in C++.
 *
 * Operators:
 * - `<<` Insertion operator (outputs data to console).
 * - `>>` Extraction operator (takes input from console).
 */

#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter the value of int a: ";
    cin >> a;

    cout << "Enter the value of int b: ";
    cin >> b;

    cout << "The value of their sum is: " << a + b;
    return 0;
}
