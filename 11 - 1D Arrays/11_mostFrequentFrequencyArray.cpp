/**
 * Problem: Find the most frequent element in an array using brute-force.
 *
 * Concepts:
 * - Brute-force: For each element, count its occurrences by comparing with all other elements.
 * - Time complexity: O(n^2), Space complexity: O(1)
 * - This is inefficient for large arrays but easy to understand.
 */

#include <iostream>
using namespace std;

int main()
{
    int n;
    int numbers[200];

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> numbers[i];

    int max_value = -1;  // Stores most frequent value
    int max_repeat = -1; // Stores its count

    for (int i = 0; i < n; ++i)
    {
        int repeat = 0;

        // Count how many times numbers[i] appears
        for (int j = 0; j < n; ++j)
            repeat += numbers[i] == numbers[j];

        // Update most frequent
        if (max_repeat == -1 || repeat > max_repeat)
        {
            max_repeat = repeat;
            max_value = numbers[i];
        }
    }

    cout << max_value << " repeated " << max_repeat << " times\n";

    return 0;
}
