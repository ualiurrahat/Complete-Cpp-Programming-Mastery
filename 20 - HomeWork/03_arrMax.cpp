/**
 * @file 03_arrMax.cpp
 * @brief Find maximum element of an array using recursion.
 */

#include <iostream>
using namespace std;

/**
 * @brief Returns the maximum value in the array.
 *
 * @param arr Array of integers
 * @param len Length of the array
 * @return int Maximum element
 *
 * @note Time Complexity: O(n)
 * @note Space Complexity: O(n)
 */
int arr_max(int arr[], int len)
{
    // Base case: only one element
    if (len == 1)
        return arr[0];

    // Recursive step: find max of first (len-1) elements
    int sub_result = arr_max(arr, len - 1);

    // Compare last element with the sub-result
    return max(sub_result, arr[len - 1]);
}

int main()
{
    int arr[] = {1, 8, 2, 10, 3};
    cout << arr_max(arr, 5); // Output: 10
    return 0;
}
