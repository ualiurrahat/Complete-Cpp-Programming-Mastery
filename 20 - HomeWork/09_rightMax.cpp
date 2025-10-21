/**
 * @file 09_rightMax.cpp
 * @brief Replace each element with the maximum value to its right using recursion.
 */

#include <iostream>
using namespace std;

/**
 * @brief Version 1: Uses start index to traverse rightwards.
 */
void right_max_v1(int arr[], int len, int start_pos = 0)
{
    // Base case: when at last element
    if (start_pos == len - 1)
        return;

    // Recursive call for next index
    right_max_v1(arr, len, start_pos + 1);

    // After recursion, update current with max of itself and right neighbor
    arr[start_pos] = max(arr[start_pos], arr[start_pos + 1]);
}

/**
 * @brief Version 2: Uses pointer shifting to simulate moving right.
 */
void right_max_v2(int arr[], int len)
{
    if (len == 1)
        return;

    // Recurse on array excluding the first element
    right_max_v2(arr + 1, len - 1);

    // Update first element based on its right neighbor
    arr[0] = max(arr[0], arr[1]);
}

int main()
{
    int arr[] = {1, 8, 2, 10, 3};
    right_max_v1(arr, 5);

    for (int i = 0; i < 5; ++i)
        cout << arr[i] << " "; // Output: 10 10 10 10 3
    return 0;
}
