/**
 * Problem: Find the three smallest elements from a list of numbers.
 *
 * Concepts and Logic:
 * - We only need to track the smallest three elements.
 * - Start by storing the first three elements.
 * - For each new element, compare it with the current three, replacing the largest of the three if the new element is smaller.
 * - Finally, sort the three elements to print in increasing order.
 * - Time complexity: O(n), Space complexity: O(1) (only three extra elements)
 */

#include <iostream>
using namespace std;

int main()
{
    int n, tmp, mn[3];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        if (i < 3)
        {
            mn[i] = value; // First three elements
        }
        else
        {
            // Find index of current maximum among mn[0..2]
            int mx_pos = 0;
            for (int j = 1; j < 3; ++j)
                if (mn[mx_pos] < mn[j])
                    mx_pos = j;

            // Replace the largest if new value is smaller
            if (value < mn[mx_pos])
                mn[mx_pos] = value;
        }
    }

    // Sort the three elements
    int mx_pos = 0;
    for (int j = 1; j < 3; ++j)
        if (mn[mx_pos] < mn[j])
            mx_pos = j;

    // Swap max with last
    tmp = mn[2];
    mn[2] = mn[mx_pos];
    mn[mx_pos] = tmp;

    // Swap first two if needed
    if (mn[0] > mn[1])
    {
        tmp = mn[0];
        mn[0] = mn[1];
        mn[1] = tmp;
    }

    for (int i = 0; i < 3; i++)
        cout << mn[i] << " ";

    cout << "\n";
    return 0;
}
