/**
 * @file 08_conditionalMathOperation.cpp
 * @brief Computes a value based on conditional input -1 or 1.
 *
 * @details
 * - Reads integer A and integer B (either -1 or 1).
 * - If B = -1, computes 2*A + 1.
 * - If B = 1, computes A*A.
 * - Uses a mathematical trick to compute in a single expression without branching.
 */

#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter A and B (-1 or 1): ";
    cin >> a >> b;

    // Compute both potential results
    int equ_is_1 = a * a;
    int equ_is_neg_1 = 2 * a + 1;

    // Convert [-1,1] to [0,1] to pick correct value
    int is_1 = (b + 1) / 2;  // 1 if b=1, 0 if b=-1
    int is_neg_1 = 1 - is_1; // 1 if b=-1, 0 if b=1

    // Single expression: pick the correct calculation
    cout << is_1 * equ_is_1 + is_neg_1 * equ_is_neg_1 << "\n";

    return 0;
}
