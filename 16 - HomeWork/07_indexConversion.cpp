/**
 * @problem
 * A 3D array can be stored in a 1D array using indexing conversion.
 * Given D (depth), R (rows), and C (columns):
 *
 * Convert between 3D index (d, r, c) and 1D index.
 *
 * Type 1 → Convert (d, r, c) → index
 * Type 2 → Convert index → (d, r, c)
 */

#include <iostream>
using namespace std;

int main()
{
    // Demonstration (disabled by default)
    if (false)
    {
        int idx = 0;
        for (int dep = 0; dep < 3; ++dep)
            for (int row = 0; row < 4; ++row)
                for (int col = 0; col < 5; ++col)
                    cout << idx++ << " = " << dep << " " << row << " " << col << "\n";
    }

    int D, R, C, type;
    int d, r, c, idx;

    cin >> D >> R >> C >> type; // Read dimensions and type of query

    int Db = R * C; // Number of elements in one depth
    int Rb = C;     // Number of elements in one row

    if (type == 1)
    {
        // Convert from (d, r, c) → index
        cin >> d >> r >> c;
        idx = d * Db + r * Rb + c * 1;
        cout << idx << "\n";
    }
    else
    {
        // Convert from index → (d, r, c)
        cin >> idx;

        // Calculate depth, row, column using division and modulus
        d = idx / Db;
        r = (idx % Db) / Rb;
        c = (idx % Db) % Rb;

        cout << d << " " << r << " " << c << "\n";
    }

    return 0;
}
