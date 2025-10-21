/**
 * @file 06_isPalindrome.cpp
 * @brief Program to check whether a number is palindrome using a function.
 */

#include <iostream>
using namespace std;

/**
 * @brief Reverses a given number.
 */
int reverse_number(int number)
{
    int reversed = 0;
    while (number > 0)
    {
        int digit = number % 10;
        reversed = reversed * 10 + digit;
        number /= 10;
    }
    return reversed;
}

/**
 * @brief Checks if a given number is palindrome.
 *
 * @param n  Number to check
 * @return true if palindrome, false otherwise
 *
 * @note Time Complexity: O(log₁₀n)
 * @note Space Complexity: O(1)
 */
bool is_palindrome(int n)
{
    return n == reverse_number(n);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (is_palindrome(n))
        cout << n << " is a palindrome.\n";
    else
        cout << n << " is not a palindrome.\n";

    return 0;
}
