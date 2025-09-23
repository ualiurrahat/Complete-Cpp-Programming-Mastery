/**
 * @file 06_continueStatement.cpp
 * @brief Demonstrates the use of continue statements in C++.
 *
 * The continue statement skips the current iteration and moves to the next.
 */

#include <iostream>
using namespace std;

int main()
{
    cout << "Printing numbers from 1 to 10, skipping multiples of 3:" << endl;

    for (int i = 1; i <= 10; i++)
    {
        if (i % 3 == 0)
        {
            continue; // skips the rest of this iteration
        }
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
