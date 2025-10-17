/**
 * @file 10_swapColumns.cpp
 * @brief Swap two columns of a given 2D array.
 *
 * @note
 * - Time complexity: O(rows)
 * - Space complexity: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    int arr[100][100];
    int rows, cols;
    cin >> rows >> cols;

    // Input matrix
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> arr[i][j];

    int c1, c2;
    cout << "Enter two column indices to swap: ";
    cin >> c1 >> c2;

    // Swap columns c1 and c2 for each row
    for (int i = 0; i < rows; ++i)
    {
        int temp = arr[i][c1];
        arr[i][c1] = arr[i][c2];
        arr[i][c2] = temp;
    }

    cout << "Matrix after swapping columns:\n";
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
