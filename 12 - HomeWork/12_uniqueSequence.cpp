/**
 * Problem:
 * Given an index `indx`, generate a special sequence:
 * - sequence[0] = 0
 * - For each i > 0:
 *     - sequence[i] = sequence[i-1] - (i-1) - 1, if positive and unused
 *     - Otherwise, sequence[i] = sequence[i-1] + (i-1) + 1
 * Output: sequence[indx]
 *
 * Intuition:
 * - At each step, we try to move backwards first.
 * - If the value is already used or negative, we move forwards.
 * - Keep track of used values in an array for O(1) checking.
 * - This ensures all sequence values are unique.
 *
 * Time complexity: O(indx)
 * Space complexity: O(indx*10) to store occurrence
 */

#include <iostream>
using namespace std;

int main()
{
    const int N = 201;
    int sequence[N];              // Store the sequence
    int occurrence[N * 10] = {0}; // Track which numbers are used
    int indx;

    cin >> indx;

    sequence[0] = 0;
    occurrence[0] = 1; // Mark 0 as used

    for (int i = 1; i <= indx; i++)
    {
        // Try to generate a smaller number first
        int cur = sequence[i - 1] - (i - 1) - 1;

        // If negative or already used, generate larger number instead
        if (cur < 0 || occurrence[cur])
            cur = sequence[i - 1] + (i - 1) + 1;

        sequence[i] = cur;
        occurrence[cur] = 1; // Mark it as used
    }

    cout << sequence[indx] << "\n";

    return 0;
}
