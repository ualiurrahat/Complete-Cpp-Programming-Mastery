/**
 * @file 04_isPrime.cpp
 * @brief Program to check whether a number is prime using a function.
 */

#include <iostream>
using namespace std;

/**
 * @brief Checks whether the given number is a prime number.
 *
 * @param n  The number to check
 * @return true if n is prime, false otherwise
 *
 * @note Time Complexity: O(√n)
 * @note Space Complexity: O(1)
 */
bool is_prime(int n)
{
    // 0 and 1 are not prime numbers
    if (n <= 1)
        return false;

    // Check divisibility up to √n
    for (int divisor = 2; divisor * divisor <= n; ++divisor)
    {
        if (n % divisor == 0)
            return false; // divisible means not prime
    }

    return true; // no divisors found
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (is_prime(n))
        cout << n << " is a prime number.\n";
    else
        cout << n << " is not a prime number.\n";

    return 0;
}
