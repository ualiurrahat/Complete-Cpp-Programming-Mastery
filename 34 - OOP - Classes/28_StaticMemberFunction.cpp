/**
 * @file 28_StaticMemberFunction.cpp
 * @brief Demonstrates `static` member functions.
 *
 * - `static` functions belong to the **class**, not an object
 * - **No `this` pointer** → cannot access non-static members
 * - Called via `Class::function()` — no object needed
 * - Useful for utility functions or factory methods
 */

#include <iostream>
#include <vector>
using namespace std;

class Test
{
public:
    int x; ///< Non-static member

    /**
     * @brief Computes factorial of n.
     * @param n Positive integer
     * @return n!
     *
     * Cannot access `x` — no `this` pointer exists.
     */
    static int factorial(int n)
    {
        // x = 10;  // ERROR: no access to non-static members

        if (n <= 1)
            return 1;
        int res = 1;
        for (int i = 2; i <= n; ++i)
            res *= i;
        return res;
    }
};

int main()
{
    cout << Test::factorial(5) << "\n"; // 120

    // No object required!
    return 0;
}