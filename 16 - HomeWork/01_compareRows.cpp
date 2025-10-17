/**
 * @problem
 * You are given a 2D array of integers with n rows and m columns.
 * Then you are given q queries. For each query, you are given two row indices (r1, r2).
 * You need to check whether every element in row r1 is strictly smaller than
 * the corresponding element in row r2.
 *
 * If for all columns j, arr[r1][j] < arr[r2][j], print "YES", otherwise print "NO".
 */

#include <iostream>
using namespace std;

int main()
{
    // Ok to not initialize. We will read immediately.
    int arr[100][100];
    int n, m;

    // Read number of rows and columns
    cin >> n >> m;

    // Reading the 2D array
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> arr[i][j]; // read each element
        }
    }

    int q;
    cin >> q; // number of queries

    while (q--)
    {
        int r1, r2;
        cin >> r1 >> r2;

        // Convert from 1-based index (input) to 0-based for array
        r1--;
        r2--;

        bool is_smaller = true; // assume r1 < r2 for all elements

        // Compare corresponding columns in both rows
        for (int j = 0; j < m; ++j)
        {
            // If any element in r1 is NOT smaller than r2, mark false
            if (arr[r1][j] >= arr[r2][j])
            {
                is_smaller = false;
                break; // no need to check further
            }
        }

        // Based on the flag, print result
        if (is_smaller)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
