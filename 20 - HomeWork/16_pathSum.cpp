/**
 * @file 16_pathSum.cpp
 * @brief Problem: Find the maximum path sum in a grid moving only right, down, or diagonally.
 */

#include <iostream>
using namespace std;

// Directions: down, right, diagonal
int di[] = {1, 0, 1};
int dj[] = {0, 1, 1};

/**
 * @brief Recursive function to find max path sum in grid
 * @param grid 2D array
 * @param ROWS Total rows
 * @param COLS Total columns
 * @param row Current row
 * @param col Current column
 * @return Maximum path sum from (row,col) to bottom-right
 */
int path_sum(int grid[100][100], int ROWS, int COLS, int row = 0, int col = 0)
{
    int sum = grid[row][col];

    // Base case: reached bottom-right
    if (row == ROWS - 1 && col == COLS - 1)
        return sum;

    int max_idx = -1, max_value = 0;

    // Check 3 possible moves: down, right, diagonal
    for (int d = 0; d < 3; ++d)
    {
        int new_row = row + di[d];
        int new_col = col + dj[d];

        if (new_row >= ROWS || new_col >= COLS)
            continue;

        if (max_value < grid[new_row][new_col])
            max_value = grid[new_row][new_col], max_idx = d;
    }

    int new_row = row + di[max_idx];
    int new_col = col + dj[max_idx];

    return sum + path_sum(grid, ROWS, COLS, new_row, new_col);
}

int main()
{
    int grid[100][100];
    int n, m;

    cin >> n >> m; // Read grid dimensions
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    cout << path_sum(grid, n, m);

    return 0;
}
