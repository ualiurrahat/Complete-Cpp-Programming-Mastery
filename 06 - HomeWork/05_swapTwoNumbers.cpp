/**
 * @file 05_swapTwoNumbers.cpp
 * @brief Swaps two numbers using a temporary variable.
 *
 * @details
 * - Reads two integers from the user.
 * - Swaps their values using a third variable.
 * - Example: num1 = 7, num2 = 231 → after swap: num1 = 231, num2 = 7.
 * - Demonstrates step-by-step swap logic for beginners.
 */

#include <iostream>
using namespace std;

int main()
{
    int num1, num2, temp;

    // Read two numbers from the user
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Swap operation using temporary variable
    temp = num2; // Step 1: store num2
    num2 = num1; // Step 2: assign num1 to num2
    num1 = temp; // Step 3: assign temp (original num2) to num1

    // Display swapped values
    cout << "After swapping: " << num1 << " " << num2 << endl;

    // Optional: For more methods of swapping, watch tutorials online
    return 0;
}
