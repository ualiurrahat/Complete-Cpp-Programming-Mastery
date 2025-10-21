/**
 * @file 06_arrayIncrement.cpp
 * @brief Increment each element in the array by its index recursively.
 */

#include <iostream>
using namespace std;

/**
 * @brief Adds index value to each element.
 *
 * @param arr Array of integers
 * @param len Length of array
 *
 * @note Time Complexity: O(n)
 * @note Space Complexity: O(n)
 */
void array_increment(int arr[], int len)
{
    // Base case: no elements left
    if (len == 0)
        return;

    // Process all previous elements first
    array_increment(arr, len - 1);

    // Then add index (len-1) to the last element
    arr[len - 1] += len - 1;
}

int main()
{
    int arr[] = {1, 8, 2, 10, 3};

    array_increment(arr, 5);

    // Print updated array
    for (int i = 0; i < 5; ++i)
        cout << arr[i] << " "; // Output: 1 9 4 13 7
    return 0;
}
