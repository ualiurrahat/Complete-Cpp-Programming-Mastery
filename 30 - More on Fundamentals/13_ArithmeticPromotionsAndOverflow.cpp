/**
 * @file 13_ArithmeticPromotionsAndOverflow.cpp
 * @brief Shows integer promotion, mixed-type arithmetic, and overflow.
 *
 * Promotion Rules:
 * - `char`, `short` → `int` before operation
 * - `int` + `double` → both become `double`
 * - Unsigned arithmetic wraps around
 */

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // int - int: normal
    cout << "20 - 30 = " << 20 - 30 << "\n"; // -10

    // unsigned int - unsigned int: wraps around
    unsigned int a = 20, b = 30;
    cout << "20u - 30u = " << a - b << "\n"; // 4294967286

    // short + int → both promoted to int
    short x = 10;
    cout << "short(10) + 90 = " << x + 90 << "\n"; // 100

    // short + int + double → all to double
    cout << "10 + 85 + 5.1 = " << x + 85 + 5.1 << "\n"; // 100.1

    // int overflow
    cout << "2000000000 + 2000000000 = " << 2000000000 + 2000000000 << "\n"; // overflow!

    // Promote one to long long to avoid overflow
    cout << "2000000000 + 2000000000LL = " << 2000000000 + 2000000000LL << "\n";

    // char promotion: both chars → int before add
    char c = CHAR_MAX;                                 // 127
    cout << "CHAR_MAX + CHAR_MAX = " << c + c << "\n"; // 254 (no overflow)

    // long long near max: subtract small double → precision loss
    long long d1 = LONG_LONG_MAX - 807;
    double d2 = d1 - 0.0; // loses lower bits
    double d3 = d1 - 100.0;
    cout << "d1: " << d1 << "\n";
    cout << "d1 as double (0.0): " << d2 << "\n";
    cout << "d1 as double (100.0): " << d3 << "\n";

    return 0;
}