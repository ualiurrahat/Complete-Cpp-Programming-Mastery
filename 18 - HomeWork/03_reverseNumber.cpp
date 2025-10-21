/**
 * @file 03_reverseNumber.cpp
 * @brief Program to reverse a number using a function.
 */

#include <iostream>
using namespace std;

/**
 * @brief Reverses the digits of an integer.
 *
 * @param number  Integer to reverse
 * @return int    Reversed integer
 *
 * @note Time Complexity: O(log₁₀n)
 * @note Space Complexity: O(1)
 */
int reverse_number(int number)
{
    int reversed = 0;

    // Continue until all digits are reversed
    while (number > 0)
    {
        int last_digit = number % 10;          // get the last digit
        reversed = reversed * 10 + last_digit; // build reversed number
        number /= 10;                          // remove last digit
    }

    return reversed;
}

int main()
{
    int n;
    cout << "Enter a number to reverse: ";
    cin >> n;

    cout << "Reversed number = " << reverse_number(n) << "\n";

    return 0;
}
