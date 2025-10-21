/**
 * @file 10_suffixSum.cpp
 * @brief Compute the sum of last `cnt` elements of an array recursively.
 */

#include <iostream>
using namespace std;

/**
 * @brief Finds suffix sum recursively.
 *
 * @param arr Array of integers
 * @param len Length of the array
 * @param cnt Number of elements to include from the end
 * @return int Suffix sum
 *
 * @note Time Complexity: O(cnt)
 * @note Space Complexity: O(cnt)
 */
int suffix_sum(int arr[], int len, int cnt)
{
    // Base case: no elements to add
    if (cnt == 0)
        return 0;

    // Take last element + suffix of smaller array
    return arr[len - 1] + suffix_sum(arr, len - 1, cnt - 1);
}

int main()
{
    int arr[] = {1, 8, 2, 10, 3};
    cout << suffix_sum(arr, 5, 3); // 10 + 2 + 3 = 15
    return 0;
}
