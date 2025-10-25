/**
 * @file 12_ImplicitConversionsAndLoss.cpp
 * @brief Illustrates implicit type conversions and data loss.
 *
 * Rules:
 * - `double` → `int`: fractional part truncated
 * - `int` → `short`: may overflow
 * - Signed → unsigned: bit pattern reinterpreted
 * - Non-zero → `bool`: `true`; only `0` → `false`
 */

#include <iostream>
using namespace std;

int main()
{
    // Any non-zero value becomes true in bool
    bool status = 42; // true
    status = -42;     // true
    status = 0;       // false
    cout << "bool from 42: " << status << ", from 0: " << status << "\n";

    // double to int: loses decimal part
    double salaryD = 100.6;
    int salaryI = salaryD; // 100
    cout << "double 100.6 → int: " << salaryI << "\n";

    // int to short: overflow (implementation-defined)
    short val = salaryI; // 100 fits in short
    cout << "int 100 → short: " << val << "\n";

    // Signed to unsigned: reinterpret bits
    signed int x = -100;
    unsigned int y = x; // Large positive number
    cout << "-100 as unsigned: " << y << "\n";

    // unsigned char from -1: all bits 1 → 255
    unsigned char blood = -1;
    cout << "-1 as unsigned char: " << (int)blood << "\n"; // 255

    return 0;
}