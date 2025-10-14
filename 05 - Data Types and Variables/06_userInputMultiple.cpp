/**
 * @file 02_userInputMultiple.cpp
 * @brief Reads two numbers from the user and prints their multiplication and sum.
 *
 * @details
 * - Demonstrates reading multiple inputs in a single line using `cin >> a >> b;`
 * - Performs arithmetic operations and displays results
 */

#include <iostream>
using namespace std;

int main()
{
    int a, b;

    // Prompt user
    cout << "Enter 2 numbers\n";

    // Read both numbers
    cin >> a >> b;

    // Print multiplication and sum
    cout << a * b << " " << a + b << "\n";

    return 0;
}
