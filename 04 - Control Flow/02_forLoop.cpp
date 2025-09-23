/**
 * @file 02_forLoop.cpp
 * @brief Demonstrates the use of for loops in C++.
 *
 * A for loop is used when the number of iterations is known beforehand.
 *
 * Syntax:
 * for (initialization; condition; update) {
 *      // loop body
 * }
 */

#include <iostream>
using namespace std;

int main()
{
    cout << "Printing numbers from 1 to 5 using for loop:" << endl;

    for (int i = 1; i <= 5; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
