/**
 * @file 03_LongLongTypes.cpp
 * @brief Shows declaration variations of `long long` and `unsigned long long`.
 *
 * Key Facts:
 * - `long long` is **at least 64 bits** (8 bytes on modern systems).
 * - Three equivalent forms:
 *     - `long long`
 *     - `unsigned long long`
 *     - `unsigned long long int` (explicit `int`)
 * - Guarantees storage for very large numbers (e.g., 64-bit counters).
 */

#include <iostream>
using namespace std;

int main()
{
    long long var1 = 0;              // Standard signed 64-bit integer
    unsigned long long var2 = 0;     // Unsigned 64-bit
    unsigned long long int var3 = 0; // Same as above — `int` is optional

    // Size is guaranteed >= 8 bytes; typically exactly 8
    cout << "sizeof(unsigned long long int): " << sizeof(var3) << " bytes\n";

    return 0;
}