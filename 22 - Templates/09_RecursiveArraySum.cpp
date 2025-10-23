/**
 * @file 09_RecursiveArraySum.cpp
 * @brief Demonstrates recursive summation of an array (non-template version).
 * 
 * This file introduces recursion as a technique for processing data, using an array summation as an example. It serves as a foundation for later variadic template recursion.
 * 
 * New Topics Introduced:
 * - **Recursion**: A function calling itself with a smaller input until a base case is reached.
 * - **Base Case**: The condition that stops recursion (here, when array length is 0).
 * 
 * The `SumArr` function recursively sums elements of an integer array by reducing the array size in each call.
 */

#include <iostream>
using namespace std;

/**
 * @brief Recursively computes the sum of an integer array.
 * @param arr The input array.
 * @param len The length of the array.
 * @return int The sum of array elements.
 */
int SumArr(int arr[], int len) {
    if (len == 0) // Base case: empty array
        return 0;
    return arr[len - 1] + SumArr(arr, len - 1); // Add last element and recurse
}

/**
 * @brief Main function to test recursive array summation.
 * @return int Program exit status.
 */
int main() {
    int a[5] = {1, 2, 3, 4, 5};
    cout << SumArr(a, 5); // Outputs 15
    return 0;
}