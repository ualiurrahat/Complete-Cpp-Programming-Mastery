/**
 * @file 04_rowOrderTraversal.cpp
 * @brief Demonstrate traversing a 2D array in row-major order.
 *
 * Row order means: access elements row by row.
 *
 * @note
 * - Time complexity: O(rows * cols)
 * - Space complexity: O(rows * cols)
 */

#include <iostream>
using namespace std;

int main()
{
    double grades[7][4] = {0};

    // Input all grades (row-major order)
    cout << "Enter 7x4 grades:\n";
    for (int row = 0; row < 7; ++row)
        for (int col = 0; col < 4; ++col)
            cin >> grades[row][col];

    // Output in row-major order
    for (int row = 0; row < 7; ++row)
    {
        cout << "Row " << row << ": ";
        for (int col = 0; col < 4; ++col)
            cout << grades[row][col] << " ";
        cout << "\n";
    }

    return 0;
}
