/**
 * @file 02_myPow.cpp
 * @brief Program to calculate power of a number using recursion.
 */

#include <iostream>
using namespace std;

/**
 * @brief Calculates value^p recursively.
 *
 * @param value Base value
 * @param p Power (defaults to 2)
 * @return int Result of value^p
 *
 * @note Time Complexity: O(p)
 * @note Space Complexity: O(p)
 */
int my_pow(int value, int p = 2)
{
    // Base case: any number to the power 0 = 1
    if (p == 0)
        return 1;

    // Recursive step: value^p = value * value^(p-1)
    return value * my_pow(value, p - 1);
}

int main()
{
    cout << my_pow(7) << "\n";    // 7^2 = 49 (default)
    cout << my_pow(7, 0) << "\n"; // 7^0 = 1
    cout << my_pow(7, 3) << "\n"; // 7^3 = 343
    return 0;
}
