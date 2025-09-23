/**
 * @file 04_doWhileLoop.cpp
 * @brief Demonstrates the use of do-while loops in C++.
 *
 * A do-while loop is similar to while loop, but guarantees at least one execution
 * of the loop body before checking the condition.
 *
 * Syntax:
 * do {
 *      // loop body
 * } while (condition);
 */

#include <iostream>
using namespace std;

int main()
{
    int count = 1;

    cout << "Printing numbers from 1 to 5 using do-while loop:" << endl;

    do
    {
        cout << count << " ";
        count++;
    } while (count <= 5);

    cout << endl;

    return 0;
}
