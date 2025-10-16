/**
 * Problem:
 * Same as previous: find subarray of length k with maximum sum
 * Optimized using sliding window.
 *
 * Intuition:
 * - Sum first k elements
 * - Slide the window one by one: remove first, add next
 * - This avoids recalculating sum each time
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    const int N = 199;
    int arr[N];
    int n, k;

    cin >> k >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int max_sum = 0, sum = 0;
    int min_index = 0;

    // Initial sum of first k elements
    for (int i = 0; i < k; i++)
        sum += arr[i];
    max_sum = sum;

    // Slide the window through the array
    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i - k] + arr[i]; // remove left, add right
        if (sum > max_sum)
        {
            max_sum = sum;
            min_index = i - (k - 1); // new start index
        }
    }

    cout << min_index << " " << min_index + k - 1 << " " << max_sum << "\n";
    return 0;
}
