/**
 * @file 01_mathOperations.cpp
 * @brief Reads 2 numbers from the user and prints their addition, subtraction, multiplication, and division.
 *
 * @details
 * - Demonstrates basic arithmetic operations: +, -, *, /.
 * - Encourages testing for edge cases:
 *      - Zero as first or second number
 *      - Negative numbers
 *      - Max int: 2147483647
 * - Uses `cin` to read user input.
 */

#include <iostream>
using namespace std;

int main()
{
    int a, b;

    // Read two numbers from the user
    cout << "Enter 2 numbers: ";
    cin >> a >> b;

    // Print arithmetic operations
    cout << a << " + " << b << " = " << a + b << "\n";
    cout << a << " - " << b << " = " << a - b << "\n";
    cout << a << " / " << b << " = " << a / b << "\n"; // integer division
    cout << a << " * " << b << " = " << a * b << "\n";

    return 0;
}

/*
Example inputs to test:
12 3
15 0
0 15
2147483647 2147483647
*/
