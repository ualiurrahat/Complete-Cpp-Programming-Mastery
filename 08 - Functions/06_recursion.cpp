/**
 * @file 06_recursion.cpp
 * @brief Demonstrates recursion by calculating factorial of a number.
 */

#include <iostream>
using namespace std;

/**
 * @brief Recursive function to calculate factorial.
 * @param a Number whose factorial is to be calculated
 * @return Factorial of the number
 */
int fact(int a)
{
    if (a == 0)
        return 1; // Base condition
    return a * fact(a - 1);
}

int main()
{
    int a;
    cout << "Enter a number to calculate its factorial: ";
    cin >> a;

    cout << "Factorial of " << a << " is: " << fact(a) << endl;
    return 0;
}
