/**
 * @file 15_VectorSizeUnderflowPitfall.cpp
 * @brief Shows danger of `v.size() - 1` when vector is empty.
 *
 * Problem:
 * - `v.size()` is `size_t` (unsigned)
 * - `v.size() - 1` when size == 0 → underflow → huge number!
 * - Loop runs billions of times → crash or freeze
 *
 * Fix: Always check `!v.empty()` or use signed loop carefully
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v; // empty

    // size_t is unsigned → 0 - 1 = 18446744073709551615
    cout << "v.size() - 1 = " << v.size() - 1 << "\n"; // huge number!

    // This loop will run ~2^64 times → infinite in practice
    cout << "Dangerous loop (casts to int):\n";
    for (int i = 0; i < (int)v.size() - 1; ++i)
        cout << "#\n";

    // This loop is skipped — still wrong logic
    cout << "Loop with unsigned comparison:\n";
    for (int i = 0; i < v.size() - 1; ++i)
        cout << "*\n";

    cout << "Tip: Always check v.empty() before using size in loops!\n";

    return 0;
}