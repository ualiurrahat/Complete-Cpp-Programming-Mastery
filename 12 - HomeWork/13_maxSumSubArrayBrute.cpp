/**
 * Problem:
 * Given an array of n elements and an integer k, find the subarray
 * of length k with the maximum sum. Output the starting index,
 * ending index, and the sum.
 *
 * Approach (Brute-force):
 * - Check every subarray of length k
 * - Compute the sum for each
 * - Track maximum sum and corresponding indices
 *
 * Intuition:
 * - For each starting position of subarray, sum next k elements
 * - Update maximum sum if current sum is larger
 *
 * Time complexity: O(n*k)
 * Space complexity: O(n) (array storage)
 */

#include <iostream>
using namespace std;

int main()
{
    const int N = 199;
    int arr[N];
    int n, k, min_index;
    int max_sum = -10000000; // Very small to start

    cin >> k >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Try every possible subarray of length k
    for (int i = 0; i <= n - k; i++)
    {
        int sum = 0;
        for (int j = 0; j < k; j++)
            sum += arr[i + j];

        // Update max_sum if current sum is bigger
        if (sum > max_sum)
        {
            max_sum = sum;
            min_index = i;
        }
    }

    cout << min_index << " " << min_index + k - 1 << " " << max_sum << "\n";

    return 0;
}
