/**
 * @file 03_inputGrades.cpp
 * @brief Read a 2D array (matrix) from user input and display it.
 *
 * This code demonstrates how to:
 * - Accept user inputs for multiple rows and columns.
 * - Display the 2D array neatly.
 *
 * @note
 * - Time complexity: O(rows * cols)
 * - Space complexity: O(rows * cols)
 */

#include <iostream>
using namespace std;

int main()
{
    double grades[7][6] = {0};

    // Input section
    cout << "Enter grades for 7 students and 4 subjects:\n";
    for (int row = 0; row < 7; ++row)
        for (int col = 0; col < 4; ++col)
            cin >> grades[row][col];

    // Output section
    for (int row = 0; row < 7; ++row)
    {
        cout << "Row " << row << ": ";
        for (int col = 0; col < 4; ++col)
            cout << grades[row][col] << " ";
        cout << "\n";
    }

    return 0;
}
