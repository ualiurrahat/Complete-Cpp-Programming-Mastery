/**
 * @file 01_length3nPlus1.cpp
 * @brief Program to find the length of the Collatz (3n + 1) sequence for a given number n.
 */

#include <iostream>
using namespace std;

/**
 * @brief Recursively computes the length of the Collatz sequence starting at n.
 *
 * @param n Starting number
 * @return int Length of the sequence (including 1)
 *
 * @note Collatz rule:
 *       - If n == 1 → stop
 *       - If n is even → n / 2
 *       - If n is odd  → 3n + 1
 * @note Time Complexity: O(sequence length)
 * @note Space Complexity: O(sequence length)
 */
int length_3n_plus_1(int n)
{
    // Base case: when n reaches 1, sequence ends
    if (n == 1)
        return 1;

    // If n is even → divide by 2 and count +1
    if (n % 2 == 0)
        return 1 + length_3n_plus_1(n / 2);

    // If n is odd → apply 3n + 1 and count +1
    return 1 + length_3n_plus_1(3 * n + 1);
}

int main()
{
    cout << length_3n_plus_1(6); // 6→3→10→5→16→8→4→2→1 → length = 9
    return 0;
}
