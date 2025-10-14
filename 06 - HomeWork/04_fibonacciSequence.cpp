/**
 * @file 04_fibonacciSequence.cpp
 * @brief Prints the first few numbers of the Fibonacci sequence.
 *
 * @details
 * - Demonstrates the Fibonacci sequence: each number is the sum of the previous two.
 * - Illustrates basic variable assignment and sequential computation.
 * - Link: https://en.wikipedia.org/wiki/Fibonacci_number
 */

#include <iostream>
using namespace std;

int main()
{
    int num1, num2, num3;

    // Initialize first two Fibonacci numbers
    num1 = 0;
    num2 = 1;

    // Compute and print next 9 Fibonacci numbers sequentially
    num3 = num1 + num2;
    cout << num3 << "\n"; // 1
    num1 = num2;
    num2 = num3;
    num3 = num1 + num2;
    cout << num3 << "\n"; // 2
    num1 = num2;
    num2 = num3;
    num3 = num1 + num2;
    cout << num3 << "\n"; // 3
    num1 = num2;
    num2 = num3;
    num3 = num1 + num2;
    cout << num3 << "\n"; // 5
    num1 = num2;
    num2 = num3;
    num3 = num1 + num2;
    cout << num3 << "\n"; // 8
    num1 = num2;
    num2 = num3;
    num3 = num1 + num2;
    cout << num3 << "\n"; // 13
    num1 = num2;
    num2 = num3;
    num3 = num1 + num2;
    cout << num3 << "\n"; // 21
    num1 = num2;
    num2 = num3;
    num3 = num1 + num2;
    cout << num3 << "\n"; // 34
    num1 = num2;
    num2 = num3;
    num3 = num1 + num2;
    cout << num3 << "\n"; // 55

    return 0;
}
