/**
 * @file 10_sumLastThreeDigits.cpp
 * @brief Compute the sum of the last three digits of a number.
 *
 * Problem Statement:
 * Given an integer, extract its last three digits and print their sum.
 */

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // Extract last three digits one by one
    int last1 = n % 10; // 1st last digit
    n /= 10;

    int last2 = n % 10; // 2nd last digit
    n /= 10;

    int last3 = n % 10; // 3rd last digit

    // Sum of last three digits
    int sum_last_three = last1 + last2 + last3;

    cout << sum_last_three << "\n";

    return 0;
}
