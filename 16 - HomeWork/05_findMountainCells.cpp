/**
 * @problem
 * Given an n × m matrix, print the indices (i, j) of all elements that are strictly
 * greater than all of their 8 possible neighbors (up, down, left, right, and diagonals).
 *
 * Such an element is called a "mountain".
 */

#include <iostream>
using namespace std;

int main()
{
    int arr[100][100];
    int n, m;

    cin >> n >> m; // Read matrix dimensions

    // Read matrix elements
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];

    // Direction arrays → represent movement in 8 directions
    // { down, right, up, left, up-left, down-right, up-right, down-left }
    int di[8] = {1, 0, -1, 0, -1, 1, -1, 1};
    int dj[8] = {0, 1, 0, -1, -1, 1, 1, -1};

    // Check each cell
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            bool valid_mountain = true; // Assume current cell is a mountain

            // Compare with all 8 neighbors
            for (int d = 0; d < 8 && valid_mountain; ++d)
            {
                int ni = i + di[d];
                int nj = j + dj[d];

                // Skip invalid positions outside matrix
                if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                    continue;

                // If any neighbor is greater or equal, not a mountain
                if (arr[i][j] <= arr[ni][nj])
                    valid_mountain = false;
            }

            // If all neighbors are smaller → print this cell
            if (valid_mountain)
                cout << i << " " << j << "\n";
        }
    }

    return 0;
}

/**
 * Example:
 * Input:
 * 1 1
 * 1
 *
 * Output:
 * 0 0
 */
