/**
 * @file 06_averagePerColumn.cpp
 * @brief Calculate average grade for each subject (column).
 *
 * @note
 * - Each column represents a subject.
 * - Average = sum of column values / number of students.
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

    // Calculate average of each subject (column)
    for (int col = 0; col < 4; ++col)
    {
        double sum = 0;
        for (int row = 0; row < 7; ++row)
            sum += grades[row][col];

        double avg = sum / 7.0;
        cout << "Subject " << col + 1 << " average: " << avg << "\n";
    }

    return 0;
}
