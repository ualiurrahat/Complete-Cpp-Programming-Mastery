/**
 * @file 16_OutputFormattingManipulators.cpp
 * @brief Demonstrates `showpos`, `setw`, `left`, `showbase`, `oct`, `hex`, `flush`.
 *
 * Useful for:
 * - Debug output
 * - Log formatting
 * - Pretty printing numbers in different bases
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Show + sign for positive numbers
    cout << showpos;
    cout << 100 << "\n";  // +100
    cout << -100 << "\n"; // -100

    cout << noshowpos;
    cout << 100 << "\n"; // 100

    // setw: field width for NEXT item only
    cout << "[" << 1234 << "]\n";            // [1234]
    cout << "[" << setw(5) << 1234 << "]\n"; // [ 1234]
    cout << "[" << setw(6) << 1234 << "]\n"; // [  1234]
    cout << "[" << setw(7) << 1234 << "]\n"; // [   1234]

    // Left-justify
    cout << left;
    cout << "[" << setw(7) << 1234 << "]\n"; // [1234   ]

    // Number bases with prefix
    cout << 15 << "\n";                     // 15
    cout << showbase << oct << 15 << "\n";  // 017
    cout << hex << 15 << "\n";              // 0xf
    cout << uppercase << hex << 15 << "\n"; // 0XF

    // Force immediate output
    cout << "something" << endl
         << flush;

    return 0;
}