/**
 * @file 08_findMaxInMatrix.cpp
 * @brief Find the maximum element in a 2D array and its position.
 *
 * @note
 * - Time complexity: O(rows * cols)
 * - Space complexity: O(rows * cols)
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

    int max_i = 0, max_j = 0;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (arr[i][j] >= arr[max_i][max_j])
            {
                max_i = i;
                max_j = j;
            }
        }
    }

    cout << "Max value at position (" << max_i << ", " << max_j
         << ") = " << arr[max_i][max_j] << endl;

    return 0;
}
