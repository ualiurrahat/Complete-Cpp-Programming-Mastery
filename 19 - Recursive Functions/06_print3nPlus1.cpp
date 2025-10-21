/**
 * @file 06_print3nPlus1.cpp
 * @brief Program to print the Collatz (3n + 1) sequence using recursion.
 */

#include <iostream>
using namespace std;

/**
 * @brief Prints the Collatz sequence starting from a given number n.
 *
 * @param n  Starting integer
 *
 * @note Collatz rule:
 *       - If n is even → n / 2
 *       - If n is odd  → 3n + 1
 *       Sequence continues until n = 1.
 *
 * @note Time Complexity: Depends on sequence length (≈ O(log n))
 * @note Space Complexity: O(sequence length)
 */
void print_3n_plus_1(int n)
{
    // Print current number
    cout << n << " ";

    // Base case: stop when n == 1
    if (n == 1)
        return;

    // If n is even, recurse with n/2
    if (n % 2 == 0)
        print_3n_plus_1(n / 2);
    else // If n is odd, recurse with 3n + 1
        print_3n_plus_1(3 * n + 1);
}

int main()
{
    print_3n_plus_1(6);
    /*
        For n = 6:
        6 → 3 → 10 → 5 → 16 → 8 → 4 → 2 → 1
    */
    return 0;
}
