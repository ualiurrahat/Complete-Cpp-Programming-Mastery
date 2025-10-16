/**
 * Problem: Reverse the elements of a 1D array in-place.
 *
 * Concepts:
 * - Swapping elements: exchange two values using a temporary variable.
 * - To reverse an array, swap the first element with the last, second with second-last, and so on.
 * - Time complexity: O(n/2) = O(n), Space complexity: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    int n;
    int numbers[200];

    // Input array size and elements
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> numbers[i];

    // Reverse the array in-place
    for (int i = 0; i < n / 2; ++i)
    {
        int last = n - i - 1;
        // Swap numbers[i] and numbers[last]
        int temp = numbers[i];
        numbers[i] = numbers[last];
        numbers[last] = temp;
    }

    // Print reversed array
    for (int i = 0; i < n; ++i)
        cout << numbers[i] << " ";
    cout << "\n";

    return 0;
}
