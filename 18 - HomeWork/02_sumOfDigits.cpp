/**
 * @file 02_sumOfDigits.cpp
 * @brief Program to find the sum of digits of a number using a function.
 */

#include <iostream>
using namespace std;

/**
 * @brief Calculates the sum of all digits in an integer.
 *
 * @param number  Integer whose digits will be summed
 * @return int    Sum of the digits
 *
 * @note Time Complexity: O(log₁₀n)
 * @note Space Complexity: O(1)
 */
int sum_of_digits(int number)
{
    int sum = 0;

    // Loop runs until all digits are processed
    while (number > 0)
    {
        int last_digit = number % 10; // extract last digit
        sum += last_digit;            // add it to sum
        number /= 10;                 // remove the last digit
    }

    return sum;
}

int main()
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    cout << "Sum of digits = " << sum_of_digits(n) << "\n";

    return 0;
}
