/**
 * @file 02_displayGrades.cpp
 * @brief Demonstrate printing a 2D array using nested loops.
 *
 * Problem:
 * Read a predefined grade matrix and display all values in a formatted way.
 *
 * @note
 * - Time complexity: O(7*4) = O(28)
 * - Space complexity: O(7*6) = O(42)
 */

#include <iostream>
using namespace std;

int main()
{
    // Step 1: Create a 2D array (7 students, 6 subjects)
    double grades[7][6] = {0};

    // Step 2: Manually assign some grades
    grades[0][0] = 50, grades[0][1] = 33, grades[0][2] = 40, grades[0][3] = 30;
    grades[1][0] = 35, grades[1][1] = 50, grades[1][2] = 40, grades[1][3] = 30;

    // Step 3: Use nested loops to display matrix
    for (int row = 0; row < 7; ++row)
    {
        cout << "Row " << row << ": ";
        for (int col = 0; col < 4; ++col)
        {
            cout << grades[row][col] << " ";
        }
        cout << "\n"; // move to next line after one row
    }

    return 0;
}
