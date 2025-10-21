/**
 * @file 17_fibonacci.cpp
 * @brief Problem: Compute nth Fibonacci number recursively
 */

#include <iostream>
using namespace std;

// Compute Fibonacci number recursively
int fib(int n)
{
    if (n <= 1)
        return 1; // Base case: first two numbers = 1
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    cout << fib(6) << "\n";  // Output: 13
    cout << fib(40) << "\n"; // Output: large Fibonacci number

    return 0;
}
