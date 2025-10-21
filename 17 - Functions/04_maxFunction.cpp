/**
 * @file 04_maxFunction.cpp
 * @brief Find maximum of two numbers using a function.
 *
 * @question
 * Implement a function that takes two integers and returns the maximum of the two.
 */

#include <iostream>
using namespace std;

/**
 * @brief Return the maximum of two integers
 * @param a first number
 * @param b second number
 * @return int maximum of a and b
 * @note Time complexity: O(1)
 */
int our_max(int a, int b)
{
    if (a >= b)
        return a;
    return b;
}

int main()
{
    cout << our_max(2, 5) << "\n";  // Output: 5
    cout << our_max(2, -5) << "\n"; // Output: 2

    return 0;
}
