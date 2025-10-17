/**
 * @problem
 * You are on an n × m grid starting at position (0, 0).
 * You are given k movement commands. Each command has a direction and number of steps.
 *
 * Directions: 1=up, 2=right, 3=down, 4=left
 * The movement wraps around the grid using modulo operations.
 * After each command, print the new position.
 */

#include <iostream>
using namespace std;

int main()
{
    int n, m, k, r = 0, c = 0;

    cin >> n >> m >> k; // Grid dimensions and number of moves

    // Direction vectors for 4 directions (up, right, down, left)
    int rd[4] = {-1, 0, 1, 0};
    int cd[4] = {0, 1, 0, -1};

    // Process k commands
    while (k--)
    {
        int dir, steps;
        cin >> dir >> steps;
        --dir; // Convert to 0-based index for rd/cd arrays

        // Update row and column with wrapping (mod n/m)
        r = (r + rd[dir] * steps) % n;
        c = (c + cd[dir] * steps) % m;

        // If we moved negative, wrap to the positive side
        if (r < 0)
            r += n;
        if (c < 0)
            c += m;

        cout << r << " " << c << "\n"; // Print current position
    }

    return 0;
}
