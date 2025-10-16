/**
 * Problem: Swap all occurrences of minimum and maximum elements in an array.
 *
 * Concepts:
 * - First, find minimum and maximum values while traversing the array.
 * - Then traverse again to replace min with max and max with min.
 * - Time complexity: O(n), Space complexity: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    const int N = 199; // Maximum expected array size
    int n, a[N];
    int mn = 10000, mx = -1; // Initialize min and max

    // Input array
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < mn)
            mn = a[i];
        if (a[i] > mx)
            mx = a[i];
    }

    // Swap occurrences of min and max
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mn)
            a[i] = mx;
        else if (a[i] == mx)
            a[i] = mn;
    }

    // Print updated array
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << " ";
        cout << a[i];
    }
    cout << "\n";

    return 0;
}
