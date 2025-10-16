/**
 * @file 12_evenOddFormula.cpp
 * @brief Demonstrates checking even/odd using a formula with only arithmetic operations.
 *
 * - Uses %2 to check if a number is even.
 * - Uses arithmetic to assign results conditionally without if/else.
 */

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // Check even using modulo
    int is_even = n % 2 == 0;
    int is_odd = 1 - is_even; // either 1 or 0

    // Conditional formula: only one part is activated
    int result = is_even * 100 + is_odd * 7;

    cout << result << "\n";

    return 0;
}
