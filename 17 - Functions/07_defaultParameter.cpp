/**
 * @file 07_defaultParameter.cpp
 * @brief Demonstrate default parameter in a function.
 *
 * @question
 * Implement a power function where the exponent has a default value.
 * If the exponent is not passed, use 3 as default.
 */

#include <iostream>
using namespace std;

/**
 * @brief Computes n raised to the power of p (default 3)
 * @param n base number
 * @param p power (default = 3)
 * @return int n^p
 */
int our_pow(int n, int p = 3)
{
    int result = 1;

    // Multiply n by itself p times
    while (p--)
        result *= n;

    return result;
}

int main()
{
    cout << our_pow(2) << "\n";    // Default power 3 → 8
    cout << our_pow(2, 3) << "\n"; // 8
    cout << our_pow(2, 4) << "\n"; // 16

    return 0;
}
