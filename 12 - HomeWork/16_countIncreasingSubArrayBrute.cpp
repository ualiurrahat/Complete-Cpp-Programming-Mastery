/**
 * Problem:
 * Given an array of n elements, count the total number of increasing subarrays.
 * A subarray is increasing if each element is greater than the previous one.
 *
 * Approach (Brute-force):
 * - Consider every possible subarray and check if it is strictly increasing
 * - Increment the result for each valid subarray
 *
 * Time complexity: O(n^3) - triple nested loops
 * Space complexity: O(n) for storing the array
 */

#include <iostream>
using namespace std;

int main()
{
    int a[199]; // Array to store the elements
    int n;      // Number of elements

    cin >> n;

    // Read array elements
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int result = 0; // To store total count of increasing subarrays

    // For every possible subarray length
    for (int len = 1; len <= n; ++len)
    {
        // Try all possible starting positions for subarray of length `len`
        for (int st = 0; st <= n - len; ++st)
        {
            bool is_ok = true; // Flag to check if subarray is increasing

            // Check if current subarray is strictly increasing
            for (int k = 1; k < len && is_ok; ++k)
            {
                if (a[st + k] <= a[st + k - 1])
                    is_ok = false; // Not increasing
            }

            // If valid, increment result
            result += is_ok;
        }
    }

    // Print total number of increasing subarrays
    cout << result << endl;

    return 0;
}
