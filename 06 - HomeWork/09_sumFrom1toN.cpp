/**
 * @file 09_sumFrom1toN.cpp
 * @brief Computes the sum of numbers from 1 to N using a formula.
 *
 * @details
 * - Reads an integer N from the user.
 * - Uses the formula sum = N*(N+1)/2 to calculate the total sum.
 * - Provides mathematical insight into why the formula works for both even and odd N.
 */

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter N: ";
    cin >> n;

    // Compute sum from 1 to N
    cout << n * (n + 1) / 2 << "\n";

    /*
     Intuition for N=8:
     1+2+3+4+5+6+7+8
     Pair numbers: (1+8), (2+7), (3+6), (4+5)
     Each pair sums to n+1=9
     Number of pairs = n/2=4
     Total sum = (n*(n+1))/2
     Works for odd N too!
     */

    return 0;
}
