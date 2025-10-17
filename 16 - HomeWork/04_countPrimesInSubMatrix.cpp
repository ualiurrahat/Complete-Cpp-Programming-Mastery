/**
 * @problem
 * Given an n × m matrix, for each query, count how many prime numbers exist
 * within a specified rectangular submatrix.
 *
 * Example:
 * Input:
 * 3 4
 * 8 16 9 52
 * 3 15 27 6
 * 14 25 29 10
 *
 * Query:
 * q = number of queries
 * For each query, read (si, sj, rows, cols)
 */

#include <iostream>
using namespace std;

int main()
{
    bool is_prime[100][100] = {0}; // To store whether each cell is prime
    int n, m, val;

    cin >> n >> m; // Read matrix dimensions

    // 🔹 Step 1: Determine if each number is prime
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> val; // Read each number

            // If number ≤ 1, not prime
            if (val <= 1)
                continue;

            is_prime[i][j] = 1; // Assume prime initially
            for (int k = 2; k < val; ++k)
            {
                if (val % k == 0)
                {
                    is_prime[i][j] = 0; // Found a divisor, not prime
                    break;
                }
            }
        }

    // 🔹 Step 2: Answer multiple submatrix queries
    int q, si, sj, rs, cls;
    cin >> q;

    while (q--)
    {
        cin >> si >> sj >> rs >> cls; // Top-left and submatrix size
        int cnt = 0;

        // Loop through the submatrix and count primes
        for (int i = si; i <= si + rs - 1; ++i)
            for (int j = sj; j <= sj + cls - 1; ++j)
                cnt += is_prime[i][j];

        cout << cnt << "\n"; // Print total count of primes
    }

    return 0;
}
