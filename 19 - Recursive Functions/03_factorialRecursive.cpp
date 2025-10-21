/**
 * @file 03_factorialRecursive.cpp
 * @brief Program to calculate factorial of a number using recursion.
 */

#include <iostream>
using namespace std;

/**
 * @brief Computes factorial recursively.
 *
 * @param n  Number whose factorial is to be calculated
 * @return int  Factorial of n
 *
 * @note Time Complexity: O(n)
 * @note Space Complexity: O(n) due to recursion stack
 */
int factorial(int n)
{
    // Print each function call to show recursion depth
    cout << "Function Call: factorial(" << n << ")\n";

    // Base case: factorial(1) = 1
    if (n == 1)
        return 1;

    // Recursive case: factorial(n) = n * factorial(n - 1)
    return factorial(n - 1) * n;
}

int main()
{
    // Example: factorial(6)
    // -> factorial(6) = 6 * factorial(5)
    // -> factorial(5) = 5 * factorial(4)
    // ... until factorial(1) = 1
    cout << factorial(6) << "\n";
    return 0;
}
