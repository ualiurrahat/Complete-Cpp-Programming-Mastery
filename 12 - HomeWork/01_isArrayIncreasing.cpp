/**
 * Problem: Check if a given array is strictly non-decreasing.
 *
 * Concepts:
 * - A non-decreasing array satisfies a[i] >= a[i-1] for all i >= 1.
 * - We can check this by traversing the array once.
 * - Time complexity: O(n), Space complexity: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    const int N = 200; // Maximum allowed size
    int n, a[N];

    // Input array size and elements
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool increasing = true; // Assume array is increasing initially

    // Check if each element is >= previous
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            increasing = false;
            break; // Early exit if array is not increasing
        }
    }

    if (increasing)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
