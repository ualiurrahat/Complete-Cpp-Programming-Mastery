/**
 * Problem: Find the value that occurs most frequently in an array with possible negative values.
 *
 * Concepts and Logic:
 * - Use a frequency array to count occurrences.
 * - Shift values to all be positive (e.g., add 500) so they can be used as indices.
 * - Then find the index with maximum frequency.
 * - Time complexity: O(n + maxValue), Space complexity: O(maxValue)
 */

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    const int MAX = 270 + 500 + 1; // Maximum possible shifted value
    int frequency[MAX] = {0};      // Initialize all counts to zero

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        value += 500; // Shift to positive index
        frequency[value]++;
    }

    int mx_pos = 0;
    for (int i = 0; i < MAX; i++)
        if (frequency[mx_pos] < frequency[i])
            mx_pos = i;

    cout << mx_pos - 500 << " has repeated " << frequency[mx_pos] << " times\n";

    return 0;
}
