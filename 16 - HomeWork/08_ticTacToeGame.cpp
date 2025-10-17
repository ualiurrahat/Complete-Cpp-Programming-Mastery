/**
 * @problem
 * Implement a Tic-Tac-Toe game for an n × n grid.
 * Two players (X and O) take turns placing their marks in empty cells.
 * The first player to get n marks in a row, column, or diagonal wins.
 * If all cells are filled and no one wins, the game is a tie.
 *
 * Input:
 * - n: grid size
 * - On each turn, player inputs row and column (1-based indexing)
 *
 * Output:
 * - Prints the grid after each move
 * - Announces the winner or tie
 */

#include <iostream>
using namespace std;

int main()
{
    // 🔹 Create grid (0 = empty, 1 = X, 2 = O)
    int grid[100][100] = {0};

    int n;
    cout << "Enter grid dimension: ";
    cin >> n;

    /*
     🔹 Idea for checking winning condition:
     - There are n rows, n columns, and 2 diagonals to check → total 2n + 2 checks
     - For each check, store:
       rs[check] = starting row
       cs[check] = starting column
       dr[check] = row direction increment
       dc[check] = column direction increment
     - Example:
       Row 0 → start (0,0), direction (0,1)
       Column 0 → start (0,0), direction (1,0)
       Diagonal → start (0,0), direction (1,1)
       Anti-diagonal → start (0,n-1), direction (1,-1)
    */

    int rs[100], cs[100], dr[100], dc[100]; // Arrays for start/direction of each check
    int verify = 0;                         // Counter for number of checks

    // Add row checks
    for (int r = 0; r < n; ++r)
        rs[verify] = r, cs[verify] = 0, dr[verify] = 0, dc[verify++] = 1;

    // Add column checks
    for (int c = 0; c < n; ++c)
        rs[verify] = 0, cs[verify] = c, dr[verify] = 1, dc[verify++] = 0;

    // Add diagonal checks
    rs[verify] = 0, cs[verify] = 0, dr[verify] = 1, dc[verify++] = 1;      // Main diagonal
    rs[verify] = 0, cs[verify] = n - 1, dr[verify] = 1, dc[verify++] = -1; // Anti-diagonal

    int turn = 0;  // 0 = X, 1 = O
    int steps = 0; // Count of moves made

    // 🔹 Main game loop
    while (true)
    {
        // If all cells filled, game is tie
        if (steps == n * n)
        {
            cout << "Tie\n";
            break;
        }

        char symbol = (turn == 0) ? 'x' : 'o'; // Determine current player symbol
        cout << "Player " << symbol << " turn. Enter empty location (r, c): ";
        int r, c;
        cin >> r >> c;
        r -= 1, c -= 1; // Convert to 0-based indexing

        // Input validation
        if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 0)
        {
            cout << "Invalid input. Try again\n";
            continue;
        }

        // Place the player's mark
        grid[r][c] = turn + 1;

        // 🔹 Print current grid
        for (int r = 0; r < n; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                char ch = '.';
                if (grid[r][c] == 1)
                    ch = 'x';
                else if (grid[r][c] == 2)
                    ch = 'o';
                cout << ch;
            }
            cout << "\n";
        }

        // 🔹 Check win conditions
        for (int check = 0; check < verify; ++check)
        {
            int r = rs[check], c = cs[check];   // Starting point
            int rd = dr[check], cd = dc[check]; // Direction
            int cnt = 0;                        // Count how many consecutive same marks
            int first = grid[r][c];             // First cell in this line

            if (first == 0)
                continue; // Skip empty start

            // Loop through the line
            for (int step = 0; step < n; ++step, r += rd, c += cd)
                cnt += grid[r][c] == first; // Increment if same symbol

            if (cnt == n)
            {
                cout << "Player " << symbol << " won\n";
                return 0; // Game ends
            }
        }

        // 🔹 Switch player for next turn
        turn = !turn;
        steps++;
    }

    return 0;
}

/*
Example Input (tie):
3
1 1
1 3
1 2
2 2
3 2
2 1
2 3
3 3
3 1
*/
