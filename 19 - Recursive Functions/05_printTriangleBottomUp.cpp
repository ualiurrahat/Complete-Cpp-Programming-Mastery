/**
 * @file 05_printTriangleBottomUp.cpp
 * @brief Program to print a right-angled triangle pattern using recursion (bottom-up approach).
 */

#include <iostream>
using namespace std;

/**
 * @brief Prints a right triangle pattern of asterisks in bottom-up order.
 *
 * @param levels  Number of rows (levels) in the triangle
 *
 * @note Time Complexity: O(n²)
 * @note Space Complexity: O(n)
 */
void print_triangle(int levels)
{
    // Base case
    if (levels == 0)
        return;

    // Recursive call first (to reach the smallest level)
    print_triangle(levels - 1);

    // After recursive call returns, print 'levels' stars
    for (int i = 0; i < levels; ++i)
        cout << "*";
    cout << "\n";
}

int main()
{
    print_triangle(5);
    /*
        Output:
        *
        **
        ***
        ****
        *****
    */
    return 0;
}
