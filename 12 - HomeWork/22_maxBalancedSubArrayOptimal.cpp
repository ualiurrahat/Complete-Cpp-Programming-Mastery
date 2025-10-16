/**
 * Problem:
 * Given an array of 0s and 1s, find the longest subarray
 * in which the number of 0s equals the number of 1s.
 *
 * Optimal Approach (Prefix Sum / Difference Array):
 * 1. Treat 0 as -1 and 1 as +1.
 * 2. Maintain a cumulative sum as you iterate through the array.
 * 3. If the same cumulative sum appears again at a later index,
 *    the subarray between the two indices has equal number of 0s and 1s.
 * 4. Use an array `difference` to store the first index at which each
 *    cumulative sum occurs. Shift the sum by 1000 to keep it positive.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n*2) for the difference array
 */

#include <iostream>
using namespace std;

int main()
{
    int n;
    int a[1000]; // Input array
    cin >> n;

    // Read array elements
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Initialize difference array to track first occurrence of each cumulative sum
    int difference[2001]; // 0-based, shifted by 1000
    for (int i = 0; i < 2001; i++)
        difference[i] = 999999; // Mark as "never appeared"

    int maxSubarrayLength = 0;      // Length of the longest balanced subarray
    int maxSubarrayStartIndex = -1; // Start index of the longest balanced subarray
    int maxSubarrayEndIndex = -1;   // End index of the longest balanced subarray

    int added = 0; // Cumulative sum where 0 is -1, 1 is +1

    // Base case: cumulative sum 0 appears before array starts at index -1
    difference[0 + 1000] = -1;

    // Iterate over the array to calculate cumulative sums
    for (int i = 0; i < n; i++)
    {
        // Treat 0 as -1, 1 as +1 for cumulative sum
        if (a[i] == 1)
            added += 1;
        else
            added -= 1;

        int shift = added + 1000; // Shift sum to keep index positive

        if (difference[shift] == 999999)
        {
            // First time this cumulative sum has appeared
            difference[shift] = i;
        }
        else
        {
            // Subarray between first occurrence and current index has equal 0s and 1s
            int subarrayLength = i - difference[shift];

            // Update maximum if this subarray is longer
            if (subarrayLength > maxSubarrayLength)
            {
                maxSubarrayLength = subarrayLength;
                maxSubarrayStartIndex = difference[shift] + 1;
                maxSubarrayEndIndex = i;
            }
        }
    }

    // Output results
    if (maxSubarrayLength == 0)
        cout << "NOT FOUND" << endl;
    else
    {
        cout << maxSubarrayLength << endl;
        for (int i = maxSubarrayStartIndex; i <= maxSubarrayEndIndex; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}
