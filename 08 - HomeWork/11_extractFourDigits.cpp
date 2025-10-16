/**
 * @file 11_extractFourthDigit.cpp
 * @brief Extract the fourth digit (from right) of an integer.
 *
 * Problem Statement:
 * Given an integer, print its fourth digit from the right.
 */

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // Remove last three digits by dividing by 1000
    // Then take %10 to get the 4th digit
    int fourth_digit = (n / 1000) % 10;

    cout << fourth_digit << "\n";

    return 0;
}
