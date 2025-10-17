/**
 * @file 09_sumOfDiagonalsAndEdges.cpp
 * @brief Compute sum of diagonals, last row, and last column of a 2D matrix.
 *
 * @note
 * - Demonstrates traversal using `while` loops.
 * - Time complexity: O(rows + cols)
 */

#include <iostream>
using namespace std;

int main()
{
    int arr[100][100];
    int rows, cols;
    cin >> rows >> cols;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> arr[i][j];

    int left_diagonal = 0, right_diagonal = 0;
    int last_row = 0, last_col = 0;

    // Left diagonal (top-left to bottom-right)
    int i = 0, j = 0;
    while (i < rows && j < cols)
        left_diagonal += arr[i++][j++];

    // Right diagonal (top-right to bottom-left)
    i = 0, j = cols - 1;
    while (i < rows && j >= 0)
        right_diagonal += arr[i++][j--];

    // Last row
    j = 0;
    while (j < cols)
        last_row += arr[rows - 1][j++];

    // Last column
    i = 0;
    while (i < rows)
        last_col += arr[i++][cols - 1];

    cout << left_diagonal << " " << right_diagonal << "\n";
    cout << last_row << " " << last_col << "\n";

    return 0;
}
