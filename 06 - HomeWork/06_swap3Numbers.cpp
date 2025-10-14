/**
 * @file 06_swapThreeNumbers.cpp
 * @brief Swaps three numbers sequentially using two-step swaps.
 *
 * @details
 * - Demonstrates breaking a complex problem (3-number swap) into simpler steps.
 * - Reads three integers from the user.
 * - Performs two separate swaps to achieve the final result.
 * - Prints the swapped numbers.
 */

#include <iostream>
using namespace std;

int main()
{
    int num1, num2, num3, temp = -1;

    cout << "Enter 3 numbers: ";
    cin >> num1 >> num2 >> num3;

    // Step 1: Swap num1 and num2
    temp = num2;
    num2 = num1;
    num1 = temp;

    // Step 2: Swap num2 and num3
    temp = num3;
    num3 = num2;
    num2 = temp;

    // Output the swapped numbers
    cout << num1 << " " << num2 << " " << num3 << "\n";

    return 0;
}
