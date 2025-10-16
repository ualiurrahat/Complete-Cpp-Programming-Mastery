/**
 * Problem:
 * Given an array of 0s and 1s, find the longest subarray
 * with equal number of 0s and 1s.
 *
 * Brute-force:
 * - Try all possible subarrays
 * - Count zeros and ones
 * - Track the maximum length and positions
 *
 * Time complexity: O(n^3)
 * Space complexity: O(n)
 */

#include <iostream>
using namespace std;

int main()
{
    int n, a[999];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int maxSubarrayLength = 0;
    int maxSubarrayStartIndex = -1;
    int maxSubarrayEndIndex = -1;

    // Try all start and end positions
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            int zerosCount = 0, onesCount = 0;

            // Count 0s and 1s in current subarray
            for (int i = start; i <= end; i++)
            {
                if (a[i] == 0)
                    zerosCount++;
                else if (a[i] == 1)
                    onesCount++;
            }

            if (zerosCount == onesCount)
            {
                int subarrayLength = end - start + 1;
                if (subarrayLength > maxSubarrayLength)
                {
                    maxSubarrayLength = subarrayLength;
                    maxSubarrayStartIndex = start;
                    maxSubarrayEndIndex = end;
                }
            }
        }
    }

    if (maxSubarrayLength == 0)
        cout << "NOT FOUND\n";
    else
    {
        cout << maxSubarrayLength << "\n";
        for (int i = maxSubarrayStartIndex; i <= maxSubarrayEndIndex; i++)
            cout << a[i] << " ";
        cout << "\n";
    }

    return 0;
}
