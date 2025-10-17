/**
 * @file 07_directionalMovement.cpp
 * @brief Demonstrate movement in a 2D grid using direction arrays.
 *
 * Directions:
 *   Down, Right, Up, Left
 *
 * @note
 * - Common in BFS, DFS, and grid-based problems.
 * - Time complexity: O(4)
 */

#include <iostream>
using namespace std;

int main()
{
    // Movement in four directions
    int di[] = {1, 0, -1, 0}; // change in row
    int dj[] = {0, 1, 0, -1}; // change in column

    int i = 4, j = 7; // starting position

    cout << "Neighboring cells of (4,7):\n";
    for (int d = 0; d < 4; ++d)
    {
        int ni = i + di[d];
        int nj = j + dj[d];
        cout << ni << " " << nj << "\n";
    }

    /*
      Expected Output:
      5 7
      4 8
      3 7
      4 6
    */

    return 0;
}
