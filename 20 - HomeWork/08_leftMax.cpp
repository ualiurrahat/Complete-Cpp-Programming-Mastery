/**
 * @file 08_leftMax.cpp
 * @brief Modify each element to be the maximum of all elements to its left.
 */

#include <iostream>
using namespace std;

/**
 * @brief Replaces each element with the maximum up to that point.
 *
 * @param arr Array of integers
 * @param len Length of array
 *
 * @note Time Complexity: O(n)
 * @note Space Complexity: O(n)
 */
void left_max(int arr[], int len)
{
    if (len == 1)
        return;

    // Process left side first
    left_max(arr, len - 1);

    // Compare current element with previous maximum
    arr[len - 1] = max(arr[len - 1], arr[len - 2]);
}

int main()
{
    int arr[] = {1, 8, 2, 10, 3};
    left_max(arr, 5);

    for (int i = 0; i < 5; ++i)
        cout << arr[i] << " "; // Output: 1 8 8 10 10
    return 0;
}
