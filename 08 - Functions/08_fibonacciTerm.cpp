/**
 * @file fibonacciTerm.cpp
 * @brief Finds nth Fibonacci term using recursion.
 */

#include <iostream>
using namespace std;

/**
 * @brief Recursive Fibonacci function.
 * @param n Position in Fibonacci sequence
 * @return nth Fibonacci term
 */
int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cout << "Enter the term position (n): ";
    cin >> n;

    cout << n << "th Fibonacci term is: " << fib(n) << endl;
    return 0;
}
