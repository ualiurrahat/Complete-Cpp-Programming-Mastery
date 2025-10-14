/**
 * @file 07_swapThreeNumbersBetter.cpp
 * @brief Circulates three numbers in a single step.
 *
 * @details
 * - Reads three integers from the user.
 * - Rotates the numbers circularly: num1 → num2, num2 → num3, num3 → num1.
 * - Uses a temporary variable for a clean swap.
 */

#include <iostream>
using namespace std;

int main()
{
    int num1, num2, num3, temp = -1;

    cout << "Enter 3 numbers: ";
    cin >> num1 >> num2 >> num3;

    // Circular swap
    temp = num1;
    num1 = num2;
    num2 = num3;
    num3 = temp;

    cout << num1 << " " << num2 << " " << num3 << "\n";

    return 0;
}
