/**
 * @file 14_CStyleVsModernCasting.cpp
 * @brief Compares C-style cast with C++ `static_cast` (safer).
 *
 * Why avoid C-style:
 * - No compile-time type safety
 * - Can silently allow dangerous conversions
 *
 * Use `static_cast` for:
 * - Numeric conversions
 * - Up/down class hierarchy
 * - void* → typed pointer (in low-level code)
 */

#include <iostream>
using namespace std;

int main()
{
    double x = 10.5;

    // C-style cast: truncates
    cout << "(int)x = " << (int)x << "\n";
    cout << "int(x) = " << int(x) << "\n"; // same

    // C++ style: explicit, safer, searchable
    cout << "static_cast<int>(x) = " << static_cast<int>(x) << "\n";

    // Dangerous: C-style allows pointer size mismatch
    char c = 10;
    int *p1 = (int *)&c; // Compiles! Undefined behavior
    // int* p2 = static_cast<int*>(&c);  // COMPILE ERROR — good!

    cout << "Warning: C-style cast allowed char* → int* (UB)\n";

    return 0;
}