/**
 * @file 04_printTriangleTopDown.cpp
 * @brief Program to print a right-angled triangle pattern using recursion (top-down approach).
 */

#include <iostream>
using namespace std;

/**
 * @brief Prints a right triangle pattern of asterisks in top-down order.
 *
 * @param levels  Number of rows (levels) in the triangle
 *
 * @note Time Complexity: O(n²)
 * @note Space Complexity: O(n) (recursion depth)
 */
void print_triangle(int levels)
{
    // Base case: stop when no levels left
    if (levels == 0)
        return;

    // Print 'levels' number of '*'
    for (int i = 0; i < levels; ++i)
        cout << "*";
    cout << "\n";

    // Recursive call to print next smaller triangle
    print_triangle(levels - 1);
}

int main()
{
    print_triangle(5);
    /*
        Output:
        *****
        ****
        ***
        **
        *
    */
    return 0;
}
