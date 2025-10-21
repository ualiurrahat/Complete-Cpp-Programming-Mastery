/**
 * @file 14_printDigits.cpp
 * @brief Problem: Print digits of a number using recursion in two ways:
 * - reversed
 * - original order
 */

#include <iostream>
using namespace std;

// Print digits in reverse order
void do_something1(int n)
{
    if (n)
    {
        cout << n % 10;        // Print last digit
        do_something1(n / 10); // Recurse for remaining digits
    }
}

// Print digits in original order
void do_something2(int n)
{
    if (n)
    {
        do_something2(n / 10); // Recurse first
        cout << n % 10;        // Then print last digit
    }
}

int main()
{
    do_something1(123456); // Output: 654321
    cout << "\n";
    do_something2(123456); // Output: 123456

    return 0;
}
