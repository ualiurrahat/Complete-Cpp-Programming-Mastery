// Using a 2D array, this program starts from the top-left cell (0,0)
// and moves through the array by always choosing the maximum value among
// the three possible moves: right, down, or diagonal (right-down).
// It keeps a running sum of the visited elements and prints the total sum.

#include <iostream>
using namespace std;

int main()
{
    int arr[100][100];

    int rows, cols;
    cin >> rows >> cols;

    // Taking input for the 2D array
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> arr[i][j];

    // Starting position from top-left corner
    int i = 0, j = 0, sum = 0;

    // Continue traversing as long as we're within the matrix boundaries
    while (i < rows && j < cols)
    {
        // Add the current cell's value to the running sum
        sum += arr[i][j];

        int next_val, best_i = -1, best_j = -1;

        // -------------------------------------------------------
        // Check all possible moves from the current position:
        // 1️⃣ Move Right  (same row, next column)
        // 2️⃣ Move Down   (next row, same column)
        // 3️⃣ Move Diagonal (next row, next column)
        // The algorithm always picks the move that has the
        // largest next cell value.
        // -------------------------------------------------------

        // is right ok position?
        if (j + 1 < cols)
            next_val = arr[i][j + 1], best_i = i, best_j = j + 1;

        // is down ok position?
        if (i + 1 < rows)
        {
            // Choose the larger value between the right and down cells
            if (best_i == -1 || next_val < arr[i + 1][j])
                next_val = arr[i + 1][j], best_i = i + 1, best_j = j;
        }

        // is diagonal ok position?
        if (i + 1 < rows && j + 1 < cols)
        {
            // Choose the diagonal if it gives a higher value
            if (next_val < arr[i + 1][j + 1]) // best_i == -1 ||   no need
                next_val = arr[i + 1][j + 1], best_i = i + 1, best_j = j + 1;
        }

        // If no valid next move, stop traversal
        if (best_i == -1)
            break;

        // Move to the chosen (best) cell
        i = best_i, j = best_j;
    }

    // Finally, print the total sum of the chosen path
    cout << sum << "\n";

    return 0;
}
