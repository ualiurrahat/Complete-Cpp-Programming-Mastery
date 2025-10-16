/**
 * @file 09_checkEven.cpp
 * @brief Demonstrates multiple ways to check if a number is even.
 *
 * Problem Statement:
 * Given an integer, check if it is even using:
 * 1. Modulus operator (%2)
 * 2. Division and checking fractional part
 * 3. Checking the last digit
 */

#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;

    // ---------------------- Method 1: Using %2 ----------------------
    bool is_even1 = (num % 2 == 0); // True if divisible by 2

    // ---------------------- Method 2: Using division ----------------------
    double by2 = static_cast<double>(num) / 2.0; // Example: 10/2=5.0, 11/2=5.5
    by2 = by2 - static_cast<int>(by2);           // Remove integer part -> 0 for even, 0.5 for odd
    bool is_even2 = (by2 == 0);

    // ---------------------- Method 3: Using last digit ----------------------
    int last_digit = num % 10; // last digit of the number
    bool is_even3 = (last_digit == 0 || last_digit == 2 || last_digit == 4 ||
                     last_digit == 6 || last_digit == 8);

    // ---------------------- Optional Output ----------------------
    // Uncomment below lines to see results
    // cout << is_even1 << " " << is_even2 << " " << is_even3 << "\n";

    return 0;
}
