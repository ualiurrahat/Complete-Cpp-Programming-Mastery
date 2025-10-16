/**
 * @file 05_breakStatement.cpp
 * @brief Demonstrates the use of break statements in C++.
 *
 * The break statement is used to exit a loop immediately,
 * regardless of the loop condition.
 */

#include <iostream>
using namespace std;

int main()
{
    cout << "Printing numbers from 1 to 10, but stopping at 5:" << endl;

    for (int i = 1; i <= 10; i++)
    {
        if (i == 5)
        {
            cout << "Breaking the loop at i = " << i << endl;
            break; // exits the loop immediately
        }
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
