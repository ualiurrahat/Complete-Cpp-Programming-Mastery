/**
 * @file 01_sumOfNumbers.cpp
 * @brief Compute the sum of numbers from 1 to n.
 *
 * @question
 * Given an integer n, calculate the sum of all integers from 1 to n.
 * Example:
 * Input: 5
 * Output: 15
 */

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n; // Input number up to which we sum

    int sum = 0; // Variable to store running total

    // Loop from 1 to n and add each value to sum
    for (int i = 1; i <= n; ++i)
        sum += i;

    cout << sum << "\n"; // Print final result

    return 0;
}
