/**
 * @problem
 * Given a matrix of size n × m, print its transpose.
 * The transpose of a matrix is obtained by flipping rows and columns.
 *
 * Example:
 * Input:
 * 3 4
 * 8 16 9 52
 * 3 15 27 6
 * 14 25 29 10
 *
 * Output:
 * 8 3 14
 * 16 15 25
 * 9 27 29
 * 52 6 10
 */

#include <iostream>
using namespace std;

int main()
{
    int arr1[100][100]; // Original matrix
    int arr2[100][100]; // Transposed matrix
    int n, m;

    cin >> n >> m; // Read matrix dimensions

    // 🔹 Input the original matrix
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr1[i][j];

    // 🔹 Compute transpose: Swap rows with columns
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            arr2[j][i] = arr1[i][j];

    // 🔹 Output the transposed matrix
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << arr2[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
