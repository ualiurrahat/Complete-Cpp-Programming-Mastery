/**
 * @file 04_arrSum.cpp
 * @brief Compute the sum of all elements in an array recursively.
 */

#include <iostream>
using namespace std;

/**
 * @brief Computes array sum recursively.
 *
 * @param arr Array of integers
 * @param len Length of the array
 * @return int Total sum of elements
 *
 * @note Time Complexity: O(n)
 * @note Space Complexity: O(n)
 */
int arr_sum(int arr[], int len)
{
    // Base case
    if (len == 1)
        return arr[0];

    // Recursively compute sum of smaller array
    int sub_result = arr_sum(arr, len - 1);

    // Add current last element
    return sub_result + arr[len - 1];
}

int main()
{
    int arr[] = {1, 8, 2, 10, 3};
    cout << arr_sum(arr, 5); // Output: 24
    return 0;
}
