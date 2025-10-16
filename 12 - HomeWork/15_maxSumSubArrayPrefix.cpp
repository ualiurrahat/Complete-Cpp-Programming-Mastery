/**
 * Problem:
 * Find subarray of length k with maximum sum using prefix sums.
 *
 * Intuition:
 * - Precompute cumulative sums in an array
 * - sum of subarray i..i+k-1 = prefix[i+k] - prefix[i]
 * - Allows O(1) subarray sum calculation
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

#include <iostream>
using namespace std;

int main()
{
    const int N = 199;
    int arr[N] = {0};
    int n, k, min_index;
    int max_sum = -10000000;

    cin >> k >> n;

    // Compute prefix sums, 1-based array
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    for (int i = k; i <= n; i++)
    {
        int current_sum = arr[i] - arr[i - k];
        if (current_sum > max_sum)
        {
            max_sum = current_sum;
            min_index = i - k + 1;
        }
    }

    cout << min_index - 1 << " " << min_index + k - 2 << " " << max_sum << "\n";

    return 0;
}
