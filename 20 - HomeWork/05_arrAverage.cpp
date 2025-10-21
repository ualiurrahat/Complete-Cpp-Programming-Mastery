/**
 * @file 05_arrAverage.cpp
 * @brief Calculate the average of an array recursively.
 */

#include <iostream>
using namespace std;

/**
 * @brief Computes average recursively using previous average formula.
 *
 * @param arr Array of doubles
 * @param len Array length
 * @return double Average of the array
 *
 * @note Time Complexity: O(n)
 * @note Space Complexity: O(n)
 */
double arr_average(double arr[], int len)
{
    // Base case
    if (len == 1)
        return arr[0];

    // Recursively compute average of smaller array
    double sub_result = arr_average(arr, len - 1);

    // Convert sub_result (average of len-1) to sum, then include current element
    sub_result = sub_result * (len - 1);

    // Compute new average
    return (sub_result + arr[len - 1]) / len;
}

int main()
{
    double arr[] = {1, 8, 2, 10, 3};
    cout << arr_average(arr, 5); // Output: 4.8
    return 0;
}
