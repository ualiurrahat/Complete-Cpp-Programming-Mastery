/**
 * @file 01_SumFunction.cpp
 * @brief Define a reusable function to sum 1 to n.
 *
 * Problem Statement:
 * Create a function that can be used in multiple files.
 *
 * New Topics Introduced:
 * - Function defined in a `.cpp` file
 * - Later moved to `.h` for reuse
 * - `#include` mechanism
 *
 * @note Time Complexity: O(n)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/**
 * @brief Calculate sum from 1 to n-1
 * @param n Upper limit (exclusive)
 * @return Sum of integers from 1 to n-1
 */
int sum_1_n(int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += i;
    return sum;
}

int main() {
    cout << sqrt(25) << "\n";        // 5
    vector<int> v;
    cout << sum_1_n(5) << "\n";      // 10
    return 0;
}