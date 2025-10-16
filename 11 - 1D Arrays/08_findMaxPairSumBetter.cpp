/**
 * Problem: Find the pair of elements with the maximum sum (optimized).
 *
 * Concepts:
 * - Avoid checking duplicate/reverse pairs.
 * - Only consider j > i to prevent duplicate pairs.
 * - Still uses nested loops, but avoids unnecessary checks.
 * - Time complexity reduced slightly, but still O(n^2) in worst case.
 */

#include <iostream>
using namespace std;

int main()
{
    int n;
    int numbers[200];

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> numbers[i];

    int idx1 = -1, idx2 = -1;

    // Only check unique pairs (i < j)
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (idx1 == -1)
            {
                idx1 = i;
                idx2 = j;
            }
            else if (numbers[idx1] + numbers[idx2] < numbers[i] + numbers[j])
            {
                idx1 = i;
                idx2 = j;
            }
        }
    }

    cout << numbers[idx1] << " " << numbers[idx2] << "\n";

    return 0;
}
