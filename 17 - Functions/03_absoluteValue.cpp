/**
 * @file 03_absoluteValue.cpp
 * @brief Compute absolute value using a custom function.
 *
 * @question
 * Implement a function that returns the absolute value of an integer.
 */

#include <iostream>
using namespace std;

/**
 * @brief Returns the absolute value of n
 * @param n input integer
 * @return int absolute value
 * @note Time complexity: O(1)
 */
int our_abs(int n)
{
    if (n >= 0)
        return n; // If positive, return as is
    return -n;    // If negative, return its positive equivalent
}

int main()
{
    cout << our_abs(5) << "\n";  // Output: 5
    cout << our_abs(-5) << "\n"; // Output: 5

    return 0;
}
