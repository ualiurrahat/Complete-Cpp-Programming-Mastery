/**
 * @file 05_FloatingPointLoopPitfall.cpp
 * @brief Shows why floating-point values must NOT be compared with == in loop conditions.
 *
 * Intuition:
 * - Most decimal fractions (0.1, 0.2, etc.) cannot be exactly represented in binary (IEEE 754).
 * - `r += 0.1` accumulates tiny errors → `r` never exactly equals 1.0.
 * - This causes **infinite loops** or incorrect iteration counts.
 *
 * Safe Alternative:
 *   Use integer loop counters or compare with epsilon.
 */

#include <iostream>
using namespace std;

int main()
{
    cout << "Increment by 0.5 (exactly representable):\n";
    for (double r = 0.0; r != 1.0; r += 0.5)
        cout << "*\n";

    cout << "\nIncrement by 0.2 (not exact):\n";
    for (double r = 0.0; r != 1.0; r += 0.2)
        cout << "#\n";

    cout << "\nIncrement by 0.1 (dangerous — may loop forever):\n";
    for (double r = 0.0; r != 1.0; r += 0.1)
        cout << "$\n";

    return 0;
}