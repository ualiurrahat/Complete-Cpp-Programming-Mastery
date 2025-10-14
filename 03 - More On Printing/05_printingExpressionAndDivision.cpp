/**
 * @file 05_printingExpressionsAndDivision.cpp
 * @brief Demonstrates printing evaluated expressions and integer vs floating-point division.
 *
 * @details
 * Shows arithmetic evaluation inside cout:
 *  - Expression evaluation
 *  - Integer division truncation (7/2 -> 3)
 *  - Floating-point division (7.0/2.0 -> 3.5)
 *  - Potential integer overflow when multiplying many large integers
 *
 * Problem statement:
 * - Print several sums, multiplications and differences and highlight
 *   how integer vs floating division behaves.
 *
 * Expected output (approx):
 * 1
 * 3
 * 6
 * 10
 * 1+2+3+4
 * 1+2+3+4=10
 *
 * 0
 * 7
 *
 * 24
 * 6
 * 2
 *
 * 3
 * 3
 * 3.5
 *
 * 1000000000  (or overflowed result depending on platform)
 * 10000000000 (may overflow on 32-bit int)
 *
 * @note Time complexity: O(1)
 * @note Space complexity: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    cout << 1 << "\n";
    cout << 1 + 2 << "\n";
    cout << 1 + 2 + 3 << "\n";
    cout << 1 + 2 + 3 + 4 << "\n";
    cout << "1+2+3+4" << "\n";
    cout << "1+2+3+4=" << 1 + 2 + 3 + 4 << "\n\n";

    cout << 1 + 2 + 3 + 4 - 10 << "\n"; // arithmetic expression result
    cout << 17 - 10 << "\n\n";

    cout << "2*3*4 = " << 2 * 3 * 4 << "\n";
    cout << "12/2 = " << 12 / 2 << "\n";
    cout << "12/2/3 = " << 12 / 2 / 3 << "\n\n";

    // Integer division:
    cout << "6/2 = " << 6 / 2 << "\n";           // 3
    cout << "7/2 = " << 7 / 2 << "\n";           // 3 (integer division truncates)
    cout << "7.0/2.0 = " << 7.0 / 2.0 << "\n\n"; // 3.5 (floating-point division)

    // Be careful — repeating multiplications may overflow int on some systems.
    // Use long long if you expect very large numbers.
    cout << 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 << "\n";      // 10^9
    cout << 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 << "\n"; // 10^10, may overflow 32-bit int

    return 0;
}
