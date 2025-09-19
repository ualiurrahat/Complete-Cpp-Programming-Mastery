/**
 * @file 01_rithmeticOperators.cpp
 * @brief Demonstrates arithmetic operators in C++.
 *
 * Operators covered:
 * ------------------
 * +  (Addition)
 * -  (Subtraction)
 * *  (Multiplication)
 * /  (Division)
 * %  (Modulus)
 */

#include <iostream>
using namespace std;

int main()
{
    int a = 15, b = 4;

    cout << "a = " << a << ", b = " << b << endl;

    cout << "Addition (a + b): " << (a + b) << endl;
    cout << "Subtraction (a - b): " << (a - b) << endl;
    cout << "Multiplication (a * b): " << (a * b) << endl;
    cout << "Division (a / b): " << (a / b) << endl; // integer division
    cout << "Modulus (a % b): " << (a % b) << endl;

    return 0;
}
