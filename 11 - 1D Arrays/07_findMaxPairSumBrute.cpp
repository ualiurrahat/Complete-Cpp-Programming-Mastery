/**
 * Problem: Find the pair of elements with the maximum sum (brute-force).
 *
 * Concepts:
 * - Brute-force approach checks all possible pairs.
 * - Time complexity is O(n^2) because each element is paired with all others.
 * - Use nested loops to consider all index combinations.
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

    int idx1 = -1, idx2 = -1;

    // Check all pairs (including pairs with same index)
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (idx1 == -1)
            {
                idx1 = i;
                idx2 = j;
            }
            else if (numbers[idx1] + numbers[idx2] < numbers[i] + numbers[j])
            {
                idx1 = i;
                idx2 = j;
            }
        }
    }

    cout << numbers[idx1] << " " << numbers[idx2] << "\n";

    return 0;
}
