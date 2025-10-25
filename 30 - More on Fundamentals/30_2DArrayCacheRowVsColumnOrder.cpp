/**
 * @file 30_2DArrayCacheRowVsColumnOrder.cpp
 * @brief Demonstrates cache performance difference between row-major and column-major access.
 *
 * Critical Concept: **Cache Locality**
 * - C++ stores 2D arrays in row-major order
 * - Accessing elements in row order → sequential memory → cache hits
 * - Accessing in column order → jumps by SZ*sizeof(int) → cache misses
 *
 * Result: go_row_order() is ~10–100x faster than go_col_order()
 */

#include <iostream>
using namespace std;

const int SZ = 7000; // Large enough to exceed cache line
int arr[SZ][SZ];     // ~196 MB → won't fit in cache

/**
 * @brief Fills array in row-major order (cache-friendly)
 *
 * Memory access pattern:
 * arr[0][0], arr[0][1], ..., arr[0][6999],
 * arr[1][0], arr[1][1], ...
 *
 * → Sequential access → excellent cache utilization
 */
void go_row_order()
{
    for (int iter = 0; iter < 10; ++iter)
        for (int i = 0; i < SZ; ++i)
            for (int j = 0; j < SZ; ++j)
                arr[i][j] = (i + j) * (iter + 1);
}

/**
 * @brief Fills array in column-major order (cache-unfriendly)
 *
 * Memory access pattern:
 * arr[0][0], arr[1][0], ..., arr[6999][0],
 * arr[0][1], arr[1][1], ...
 *
 * → Strided access (7000 * 4 = 28KB jump) → cache thrashing
 */
void go_col_order()
{
    for (int iter = 0; iter < 10; ++iter)
        for (int j = 0; j < SZ; ++j)
            for (int i = 0; i < SZ; ++i)
                arr[i][j] = (i + j) * (iter + 1);
}

int main()
{
    go_row_order(); // Fast due to spatial locality
    // go_col_order(); // Uncomment to observe massive slowdown

    return 0;
}