/**
 * @file 27_RecursiveFunctionsFactorialAndCollatz.cpp
 * @brief Explores recursion via factorial and Collatz-like sequence.
 *
 * Two independent examples:
 * 1. Iterative factorial (non-recursive)
 * 2. Recursive pair f1/f2 simulating Collatz conjecture steps
 *
 * Key Concept: Mutual recursion between f1 and f2
 */

#include <iostream>
using namespace std;

/**
 * @brief Computes factorial iteratively
 * @param n Input number (n >= 0)
 * @return n! (factorial of n)
 *
 * Intuition: Multiply from 1 to n sequentially
 */
int factorial(int n)
{
    int ret = 1;
    for (int i = 1; i <= n; ++i)
        ret *= i;
    return ret;
}

/**
 * @brief Recursive function for even numbers
 * @param n Current number (assumed even)
 * @return Count of steps to reach 1 via modified Collatz rules
 *
 * Rule: if n even → n/2
 */
int f1(int n);

/**
 * @brief Recursive function for odd numbers
 * @param n Current number (assumed odd)
 * @replacement Rule: if n odd → 3n+1
 */
int f2(int n);

/**
 * @brief Entry point for even n
 *
 * Prints current n, then:
 * - If even: go to f1(n/2)
 * - If odd: go to f2(n)
 */
int f1(int n)
{
    cout << n << "\n";
    if (n % 2 == 0)
        return 1 + f1(n / 2); // Even: divide by 2
    return f2(n);             // Odd: delegate to f2
}

/**
 * @brief Entry point for odd n
 *
 * Prints current n, then:
 * - If n == 1: return 1
 * - If odd: go to f1(3n+1)
 * - If even: go to f1(n) — though this shouldn't happen
 */
int f2(int n)
{
    cout << n << "\n";
    if (n == 1)
        return 1;

    if (n % 2 == 1)
        return 1 + f1(3 * n + 1); // Odd: 3n+1
    return f1(n);                 // Even: delegate (defensive)
}

int main()
{
    // Start recursion with 5 (odd → goes to f2 → f1)
    cout << f1(5) << "\n"; // Output: total steps to reach 1

    return 0;
}