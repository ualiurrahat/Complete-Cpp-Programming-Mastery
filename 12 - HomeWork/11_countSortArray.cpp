/**
 * Problem: Sort an array using count sort algorithm (values are small and non-negative).
 *
 * Concepts and Logic:
 * - Count sort: count occurrences of each value, then print each value frequency times.
 * - Very efficient when maximum value is small.
 * - Time complexity: O(n + maxValue), Space complexity: O(maxValue)
 */

#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    int n;
    cin >> n;

    const int MAX = 500 + 1;
    int frequency[MAX] = {0};

    // Count frequency of each value
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        assert(0 <= value && value <= 500);
        frequency[value]++;
    }

    // Print sorted array by frequency
    for (int i = 0; i < MAX; ++i)
    {
        while (frequency[i] > 0)
        {
            cout << i << " ";
            --frequency[i];
        }
    }
    cout << "\n";

    return 0;
}
