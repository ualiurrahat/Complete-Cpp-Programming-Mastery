/**
 * @file 04_IntegerSuffixesAndLargeConstants.cpp
 * @brief Explains integer literal suffixes and handling of large constants.
 *
 * Suffixes control the **type** of a literal:
 * - No suffix → `int`
 * - `u`  → `unsigned int`
 * - `l`  → `long`
 * - `ll` → `long long`
 * - `ull`→ `unsigned long long`
 *
 * Large constants **must** fit into their type or cause compilation error.
 */

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // ---------------------------------------------------------------------
    // Literal suffixes determine type
    // ---------------------------------------------------------------------
    cout << 2 << "\n";   // int
    cout << 2u << "\n";  // unsigned int
    cout << 2l << "\n";  // long
    cout << 2ll << "\n"; // long long

    // ---------------------------------------------------------------------
    // Maximum values from <climits>
    // ---------------------------------------------------------------------
    cout << INT_MAX << "\n";    // 2147483647
    cout << LONG_MAX << "\n";   // usually 9223372036854775807
    cout << LLONG_MAX << "\n";  // same as LONG_MAX on 64-bit
    cout << ULLONG_MAX << "\n"; // 18446744073709551615

    // ---------------------------------------------------------------------
    // Large constants require correct suffix
    // ---------------------------------------------------------------------
    cout << 2147483647 << "\n";            // Fits in signed int
    cout << 9223372036854775807ll << "\n"; // Must use `ll` — too big for `int` or `long`

    // This would cause compilation error (exceeds signed long long):
    // cout << 18446744073709551615 << "\n";

    cout << 2147483647ull << "\n";           // unsigned long long
    cout << 18446744073709551615ull << "\n"; // Largest standard integer

    // ---------------------------------------------------------------------
    // Non-standard 128-bit integer (GCC/Clang extension)
    // ---------------------------------------------------------------------
    // __int128_t x = 18446744073709551615ull;
    // ++x;
    // cout << x << "\n";  // Requires custom printer (not standard)

    return 0;
}