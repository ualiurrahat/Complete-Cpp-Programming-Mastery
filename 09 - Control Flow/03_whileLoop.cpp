/**
 * @file 03_whileLoop.cpp
 * @brief Demonstrates the use of while loops in C++.
 *
 * A while loop is used when the number of iterations is not known in advance.
 * It keeps executing as long as the condition is true.
 *
 * Syntax:
 * while (condition) {
 *      // loop body
 * }
 */

#include <iostream>
using namespace std;

int main()
{
    int count = 1;

    cout << "Printing numbers from 1 to 5 using while loop:" << endl;

    while (count <= 5)
    {
        cout << count << " ";
        count++;
    }
    cout << endl;

    return 0;
}
