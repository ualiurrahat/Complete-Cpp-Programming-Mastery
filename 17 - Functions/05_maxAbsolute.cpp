/**
 * @file 05_maxAbsolute.cpp
 * @brief Find the maximum of absolute values of two integers.
 *
 * @question
 * Implement a function that finds which number has the greater absolute value.
 */

#include <iostream>
using namespace std;

// Helper function to return absolute value
int our_abs(int n)
{
    if (n >= 0)
        return n;
    return -n;
}

/**
 * @brief Return maximum of absolute values of two integers
 * @param a first number
 * @param b second number
 * @return int larger absolute value
 */
int our_max2(int a, int b)
{
    a = our_abs(a);
    b = our_abs(b);

    if (a >= b)
        return a;
    return b;
}

int main()
{
    cout << our_max2(2, 5) << "\n";  // Output: 5
    cout << our_max2(2, -5) << "\n"; // Output: 5

    return 0;
}
