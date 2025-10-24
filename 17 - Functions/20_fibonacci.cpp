/**
 * @file 07_fibonacci.cpp
 * @brief Prints Fibonacci sequence up to n terms using iteration.
 */

#include <iostream>
using namespace std;

/**
 * @brief Prints Fibonacci series up to n terms.
 * @param n Number of terms
 */
void fibonacci(int n)
{
    int a = 0, b = 1, c = 1;

    for (int i = 1; i <= n; i++)
    {
        cout << c << ", ";
        c = a + b;
        a = b;
        b = c;
    }
}

int main()
{
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Fibonacci series up to " << n << " terms:\n0, ";
    fibonacci(n);

    return 0;
}
