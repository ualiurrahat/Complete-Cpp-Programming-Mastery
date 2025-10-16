/**
 * @file 02_commaOperatorFibonacci.cpp
 * @brief Demonstrates chained comma operator for sequential expressions.
 *
 * The program uses the comma operator (`,`) to execute multiple statements
 * inside a single expression, which is sometimes used for compact Fibonacci sequence updates.
 *
 * ⚠️ Note:
 *   Although valid, using the comma operator like this is discouraged for readability.
 */

#include <iostream>
using namespace std;

int main()
{
    int a = 1, b = 1, c;

    // Using the comma operator to chain updates.
    // Each expression executes from left to right.
    cout << (c = a + b, // c = 2
             a = b,     // a = 1
             b = c,     // b = 2
             c = a + b, // c = 3
             a = b,     // a = 2
             b = c,     // b = 3
             c = a + b, // c = 5
             a = b,     // a = 3
             b = c,     // b = 5
             c = a + b, // c = 8
             a = b,     // a = 5
             b = c,     // b = 8
             c)         // Final value of c = 13
         << endl;

    // Output = 13 (after performing four Fibonacci-like steps)
    return 0;
}
