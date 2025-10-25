/**
 * @file 29_InlineFunctionMaxExample.cpp
 * @brief Shows use of inline function to avoid function call overhead.
 *
 * Intuition:
 * - Small functions benefit from inlining
 * - Compiler replaces function call with body
 * - Reduces stack overhead, improves speed
 */

#include <iostream>
using namespace std;

/**
 * @brief Inline function to find maximum of two integers
 * @param a First integer
 * @param b Second integer
 * @return Larger of a and b
 *
 * Why inline?
 * - Only 2 comparisons → very fast
 * - Inlining eliminates call/return overhead
 */
inline int mymax(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    // Function call replaced with: ((2 > 3) ? 2 : 3)
    cout << mymax(2, 3); // Output: 3

    return 0;
}