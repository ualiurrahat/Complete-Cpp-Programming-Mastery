/**
 * @problem_statement
 * Write a function that calculates the sum of the first N elements of an integer array.
 */

#include <iostream>
using namespace std;

/**
 * @brief Computes the sum of the first 'len' elements of an array.
 *
 * @param arr (int[]) Input integer array.
 * @param len (int) Number of elements to sum.
 * @return int The computed sum of the specified range.
 *
 * @note Time complexity: O(len)
 * @note Space complexity: O(1)
 */
int sum_array(int arr[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; ++i)
        sum += arr[i];
    return sum;
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};

    // Compute sum of first 3 elements → 1 + 2 + 3 = 6
    cout << sum_array(arr, 3) << "\n";

    // Compute sum of all 6 elements → 21
    cout << sum_array(arr, 6) << "\n";

    return 0;
}
