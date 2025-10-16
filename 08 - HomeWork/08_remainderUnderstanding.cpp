/**
 * @file 08_remainderUnderstanding.cpp
 * @brief Demonstrate the concept of remainder using arithmetic and modulus operator.
 *
 * Problem Statement:
 * Given two integers `n` and `m`, compute the remainder when n is divided by m
 * using both manual arithmetic and the modulus (%) operator.
 */

#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // Example explanation:
    // 13 / 5 = 2 (2 full units of 5)
    // 2 * 5 = 10 (total full units)
    // Remainder = 13 - 10 = 3
    int remainderByFormula = n - (n / m) * m;

    // Output both manual and built-in modulus results
    cout << remainderByFormula << " " << n % m << "\n";

    return 0;
}
