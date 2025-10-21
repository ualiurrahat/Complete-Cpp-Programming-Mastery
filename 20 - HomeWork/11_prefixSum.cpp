/**
 * @file 11_prefixSum.cpp
 * @brief Problem: Compute the prefix sum of an array using recursion.
 * Two versions:
 * - v1: using current count index
 * - v2: shifting the array pointer
 */

#include <iostream>
using namespace std;

/**
 * @brief Prefix sum using count index (v1)
 * @param arr The array
 * @param len Total length of array (not used here)
 * @param cnt Number of elements to sum
 * @return Sum of first cnt elements
 */
int prefix_sum_v1(int arr[], int len, int cnt)
{
    if (cnt == 0)
        return 0;

    return arr[cnt - 1] + prefix_sum_v1(arr, len - 1, cnt - 1);
}

/**
 * @brief Prefix sum using array pointer (v2)
 * @param arr The array (or shifted array)
 * @param cnt Number of elements to sum
 * @return Sum of first cnt elements
 */
int prefix_sum_v2(int arr[], int cnt)
{
    if (cnt == 0)
        return 0;

    return arr[0] + prefix_sum_v2(arr + 1, cnt - 1);
}

int main()
{
    int arr[] = {1, 8, 2, 10, 3};

    // Sum first 3 elements using v1
    cout << prefix_sum_v1(arr, 5, 3) << "\n";

    // Sum first 3 elements using v2
    cout << prefix_sum_v2(arr, 3) << "\n";

    return 0;
}
