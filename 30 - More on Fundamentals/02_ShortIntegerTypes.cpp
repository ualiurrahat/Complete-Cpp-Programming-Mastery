/**
 * @file 02_ShortIntegerTypes.cpp
 * @brief Explores `short` and `unsigned short` — smaller integer types with wrap-around.
 *
 * Key Points:
 * - `short` is at least 16 bits (typically 2 bytes).
 * - Signed by default; `unsigned short` doubles the positive range.
 * - Overflow/underflow wraps around (circular arithmetic).
 * - Useful when memory is tight (e.g., embedded systems).
 */

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // ---------------------------------------------------------------------
    // Signed short
    // ---------------------------------------------------------------------
    short short_var1 = -10;
    signed short short_var2 = -10; // Same as `short`

    cout << short_var2 << ": " << sizeof(short_var1) << " bytes\n";

    cout << SHRT_MIN << " " << SHRT_MAX << "\n"; // e.g., -32768 32767

    short_var1 = SHRT_MAX + 1; // Overflow → wraps to SHRT_MIN
    cout << "Overflow (SHRT_MAX + 1): " << short_var1 << "\n";

    // ---------------------------------------------------------------------
    // Unsigned short
    // ---------------------------------------------------------------------
    unsigned short short_var3 = USHRT_MAX; // Max: 65535
    cout << "Unsigned short range: 0 " << short_var3 << "\n";

    ++short_var3; // Overflow → 0
    cout << "Overflow (++USHRT_MAX): " << short_var3 << "\n";

    short_var3 = -1; // Underflow → USHRT_MAX
    cout << "Underflow (-1): " << short_var3 << "\n";

    short_var3 = -2; // Underflow → 65534
    cout << "Underflow (-2): " << short_var3 << "\n";

    return 0;
}