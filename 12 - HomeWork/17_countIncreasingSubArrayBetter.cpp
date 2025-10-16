/**
 * Problem:
 * Count total number of increasing subarrays.
 * Optimized approach:
 * - Start from each index and expand as long as subarray is increasing
 *
 * Intuition:
 * - Any subarray of size 1 is increasing
 * - Expand subarray from current start as long as next element >= previous
 * - Stop when condition fails
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 */

#include <iostream>
using namespace std;

int main()
{
    int a[199]; // Array to store input
    int n;      // Number of elements

    cin >> n;

    // Read array elements
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int result = 0; // Total number of increasing subarrays

    // Consider each element as start of subarray
    for (int i = 0; i < n; i++)
    {
        result++; // Single element is always increasing

        // Expand subarray to the right
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] >= a[j - 1]) // Still increasing
                result++;
            else
                break; // Stop expanding when condition fails
        }
    }

    cout << result << endl;
    return 0;
}
