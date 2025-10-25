/**
 * @file 02_SumImplementation.cpp
 * @brief Implementation of `sum_1_n` and definition of shared global.
 *
 * @note `total_calls_global` – file-scope, **not visible** outside this file.
 * @note `total_calls_st_global` – `static`, also file-scope only.
 * @note `visibile_anywere` – **definition** of the `extern` variable.
 */

#include "01_SumHeader.cpp"
#include <iostream>
using namespace std;

/* File-scope counters – not accessible from other .cpp files */
int total_calls_global = 0;
static int total_calls_st_global = 0;

/* Definition of the extern variable declared in the header */
int visibile_anywere = 0;

int sum_1_n(int n)
{
    ++total_calls_global;
    ++total_calls_st_global;
    ++visibile_anywere;
    ++st_gl_per_include; // each .cpp has its own copy!

    cout << "total_calls_global=" << total_calls_global
         << " total_calls_st_global=" << total_calls_st_global
         << " st_gl_per_include=" << st_gl_per_include
         << " visibile_anywere=" << visibile_anywere << "\n";

    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += i;
    return sum;
}