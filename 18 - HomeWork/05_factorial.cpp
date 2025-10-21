/**
 * @file 05_factorial.cpp
 * @brief Program to calculate factorial of a number using a function.
 */

#include <iostream>
using namespace std;

/**
 * @brief Computes factorial of a given number n.
 *
 * @param n  Number whose factorial is required
 * @return long long  Factorial result
 *
 * @note Time Complexity: O(n)
 * @note Space Complexity: O(1)
 */
long long factorial(int n)
{
    long long fact = 1;

    for (int i = 1; i <= n; ++i)
        fact *= i; // multiply by each number sequentially

    return fact;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial of " << n << " = " << factorial(n) << "\n";

    return 0;
}
