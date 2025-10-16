/**
 * Problem: For each query number, find the last occurrence index in an array.
 *
 * Concepts:
 * - Brute-force approach: search from the end of the array for each query.
 * - Time complexity: O(n*q), where q = number of queries
 * - Space complexity: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    int n, q, a[200];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;

        int pos = -1;

        // Search from the end to find last occurrence
        for (int i = n - 1; i >= 0; --i)
        {
            if (a[i] == num)
            {
                pos = i;
                break;
            }
        }
        cout << pos << "\n";
    }

    return 0;
}
