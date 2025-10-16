/**
 * Problem:
 * Same as previous, but optimize by checking subarrays starting at each index.
 *
 * Intuition:
 * - Expand subarray from start index
 * - Count zeros and ones dynamically
 * - Update maximum length if counts match
 *
 * Time complexity: O(n^2)
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

    // Expand subarray from each start index
    for (int start = 0; start < n; start++)
    {
        int zerosCount = 0, onesCount = 0;

        for (int end = start; end < n; end++)
        {
            if (a[end] == 0)
                zerosCount++;
            else
                onesCount++;

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
