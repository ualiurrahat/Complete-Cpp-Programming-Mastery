// This version of the previous program uses two arrays `di` and `dj`
// to represent the direction offsets (down, right, diagonal).
// The logic is the same: start from (0,0) and always move to the
// neighboring cell that has the maximum value among those 3 possible moves.

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

    int i = 0, j = 0, sum = 0;

    // These arrays define the 3 possible directions:
    // di[] = change in row, dj[] = change in column
    // (1,0) -> down, (0,1) -> right, (1,1) -> diagonal
    int di[3]{1, 0, 1};
    int dj[3]{0, 1, 1};

    // Continue traversal until we go out of matrix bounds
    while (i < rows && j < cols)
    {
        // Add the current element to sum
        sum += arr[i][j];

        int next_val, best_i = -1, best_j = -1;

        // -------------------------------------------------------
        // Try all 3 possible directions defined in di[] and dj[].
        // Compare the values of reachable cells and select the one
        // with the maximum value to move to.
        // -------------------------------------------------------
        for (int d = 0; d < 3; ++d)
        {
            int ni = i + di[d], nj = j + dj[d]; // next row, next column

            // Check if (ni, nj) is within valid bounds
            if (ni < rows && nj < cols)
            {
                // If first valid move or better than previous best
                if (best_i == -1 || next_val < arr[ni][nj])
                    next_val = arr[ni][nj], best_i = ni, best_j = nj;
            }
        }

        // Stop if no further valid moves are possible
        if (best_i == -1)
            break;

        // Move to the selected best cell
        i = best_i, j = best_j;
    }

    // Print the total sum of the path chosen
    cout << sum << "\n";

    return 0;
}
