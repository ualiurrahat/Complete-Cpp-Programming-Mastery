/**
 * @file 03_Main.cpp
 * @brief Demo that calls `sum_1_n` multiple times and shows the counter.
 *
 * @note The counter lives in the implementation file; main only sees the `extern` declaration.
 */

#include <iostream>
#include "01_SumHeader.cpp" // header from the same sub-folder
using namespace std;

int main()
{
    // First batch
    for (int i = 0; i < 3; ++i)
        sum_1_n(10);

    // Simulate some other work
    total_calls += 100; // direct manipulation of the global

    // Second batch
    for (int i = 0; i < 3; ++i)
        sum_1_n(10);

    return 0;
}