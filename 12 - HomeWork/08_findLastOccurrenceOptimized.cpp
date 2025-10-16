/**
 * Problem: For each query number, find the last occurrence index using a precomputed array.
 *
 * Concepts and Logic:
 * - Since values are small (0-500), we can use an array to store last occurrence of each value.
 * - This allows O(1) answer per query instead of searching each time.
 * - Time complexity: O(n + q), Space complexity: O(maxValue)
 */

#include <iostream>
using namespace std;

int main()
{
    const int N = 500 + 1; // Maximum possible value
    int n, q, x;
    int ans[N];

    // Initialize all answers to -1
    for (int i = 0; i < N; i++)
        ans[i] = -1;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        ans[x] = i; // Update last occurrence of x
    }

    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;
        cout << ans[num] << "\n";
    }

    return 0;
}
