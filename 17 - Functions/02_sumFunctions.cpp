/**
 * @file 02_sumFunction.cpp
 * @brief Use a function to compute the sum of numbers from 1 to n.
 *
 * @question
 * Write a function that takes an integer n and returns the sum of numbers from 1 to n.
 */

#include <iostream>
using namespace std;

/**
 * @brief Compute sum of integers from 1 to n
 * @param n upper limit
 * @return int sum of numbers
 * @note Time complexity: O(n), Space complexity: O(1)
 */
int sum1_to_n(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += i; // Add current number to running sum
    return sum;
}

int main()
{
    int n;
    cin >> n;                  // Input number
    int result = sum1_to_n(n); // Call the function

    cout << result << "\n"; // Output result

    return 0;
}
