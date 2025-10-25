/**
 * @file 02_SumImplementation.cpp
 * @brief Source file – **definition** of the function and the global variable.
 *
 * @note The `extern` variable is *defined* (and initialized) exactly once.
 */

#include <iostream>
#include "01_SumHeader.cpp" // header from the same sub-folder
using namespace std;

/** Definition (initialization) of the global counter. */
int total_calls = 0;

int sum_1_n(int n)
{
    ++total_calls;
    cout << "Total_calls " << total_calls << "\n";

    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += i;
    return sum;
}