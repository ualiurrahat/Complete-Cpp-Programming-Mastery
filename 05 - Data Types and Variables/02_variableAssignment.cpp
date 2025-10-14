/**
 * @file 02_variableAssignment.cpp
 * @brief Demonstrates variable declaration, assignment, reassignment, and basic arithmetic.
 *
 * @details
 * - Declare variables to reserve memory.
 * - Assign values to variables.
 * - Reassign variables to store new values.
 * - Perform arithmetic operations: addition, subtraction, and formula.
 */

#include <iostream>
using namespace std;

int main()
{
    // Declare integer variables (initially contain garbage values)
    int number1;
    int number2;

    // Assign values
    number1 = 30;
    number2 = 10;

    // Perform arithmetic
    cout << number1 + number2 << "\n"; // 40
    cout << number1 - number2 << "\n"; // 20

    // Reassign value
    number1 = 50;
    cout << "2n+1 = " << number1 * 2 + 1 << "\n"; // 2*50 + 1 = 101

    return 0;
}
