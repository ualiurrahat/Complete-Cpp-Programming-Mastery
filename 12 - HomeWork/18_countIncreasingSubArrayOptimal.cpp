/**
 * Problem:
 * Count total number of increasing subarrays using optimal method
 * (like counting lengths of consecutive increasing sequences).
 *
 * Intuition:
 * - If we have a sequence of length L, it contains L*(L+1)/2 increasing subarrays
 * - Instead of nested loops, we keep track of length and incrementally calculate
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

#include <iostream>
using namespace std;

int main()
{
    int a[199]; // Input array
    int n;      // Number of elements
    cin >> n;

    // Read input elements
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int result = 0; // Total number of increasing subarrays
    int len = 1;    // Current length of increasing subarray

    // Start from second element
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] <= a[i])
        {
            // Extend the increasing sequence
            result += len;
            len++;
        }
        else
        {
            // Sequence broken, reset length
            len = 1;
        }
    }

    // Add subarrays of length 1 (single elements)
    cout << result + n << endl;
    return 0;
}
