/**
 * @file 01_factorialIterative.cpp
 * @brief Program to calculate factorial of a number using an iterative approach.
 */

#include <iostream>
using namespace std;

/**
 * @brief Computes the factorial of a given number iteratively.
 *
 * @param n  The number whose factorial is to be calculated
 * @return int  Factorial of n
 *
 * @note Time Complexity: O(n)
 * @note Space Complexity: O(1)
 */
int factorial(int n)
{
    int result = 1;

    // Multiply result by each number from 2 to n
    for (int i = 2; i <= n; ++i)
        result *= i;

    return result;
}

int main()
{
    // Demonstrating the factorial function with examples
    cout << factorial(3) << "\n"; // 1 * 2 * 3 = 6
    cout << factorial(4) << "\n"; // 1 * 2 * 3 * 4 = 24
    cout << factorial(5) << "\n"; // 1 * 2 * 3 * 4 * 5 = 120
    cout << factorial(6) << "\n"; // 1 * 2 * 3 * 4 * 5 * 6 = 720

    return 0;
}
