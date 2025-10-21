/**
 * @file 07_accumulateArray.cpp
 * @brief Transform array so that each element becomes sum of all previous elements.
 */

#include <iostream>
using namespace std;

/**
 * @brief Converts array to cumulative form using recursion.
 *
 * @param arr Array of integers
 * @param len Length of the array
 *
 * @note Time Complexity: O(n)
 * @note Space Complexity: O(n)
 */
void accumulate_arr(int arr[], int len)
{
    // Base case
    if (len == 1)
        return;

    // Recurse on smaller array
    accumulate_arr(arr, len - 1);

    // Add previous value to current
    arr[len - 1] += arr[len - 2];
}

int main()
{
    int arr[] = {1, 8, 2, 10, 3};
    accumulate_arr(arr, 5);

    for (int i = 0; i < 5; ++i)
        cout << arr[i] << " "; // Output: 1 9 11 21 24
    return 0;
}
