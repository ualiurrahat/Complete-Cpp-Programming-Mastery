/**
 * @problem
 * Given an n x n square matrix, calculate:
 * 1️⃣ The sum of all elements on or above the main diagonal (upper sum).
 * 2️⃣ The sum of all elements on or below the main diagonal (lower sum).
 *
 * Then print both sums in separate lines.
 */

#include <iostream>
using namespace std;

int main()
{
    int n, upper = 0, lower = 0, val;

    // Read the size of the square matrix
    cin >> n;

    // ⚡ No need to store the entire matrix.
    // We'll process each input value immediately as we read it.

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> val; // Read each matrix element

            // 🧮 The main diagonal divides the matrix into two regions:
            // Elements where i <= j belong to the upper triangle (including diagonal).
            // Elements where i >= j belong to the lower triangle (including diagonal).

            if (i <= j)
                lower += val; // element is part of upper region or diagonal

            if (i >= j)
                upper += val; // element is part of lower region or diagonal
        }
    }

    // Print both sums
    cout << lower << "\n"; // first sum (upper region)
    cout << upper << "\n"; // second sum (lower region)

    return 0;
}
