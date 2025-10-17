/**
 * @file 05_columnOrderTraversal.cpp
 * @brief Demonstrate traversing a 2D array column by column (column-major order).
 *
 * Column order means: access elements column by column.
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

    cout << "Enter 7x4 grades:\n";
    for (int row = 0; row < 7; ++row)
        for (int col = 0; col < 4; ++col)
            cin >> grades[row][col];

    cout << "Displaying column by column:\n";
    for (int col = 0; col < 4; ++col)
    {
        cout << "Col " << col << ": ";
        for (int row = 0; row < 7; ++row)
            cout << grades[row][col] << " ";
        cout << "\n";
    }

    return 0;
}
