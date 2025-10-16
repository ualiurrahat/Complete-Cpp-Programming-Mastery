/**
 * Problem: Find the two largest numbers in an array using a brute-force method.
 *
 * Concepts:
 * - Brute-force approach checks all elements repeatedly.
 * - First, find the maximum element.
 * - Temporarily remove it (assign a very small value).
 * - Then find the second maximum.
 * - 1D arrays store elements in contiguous memory and are accessed using indices.
 */

#include <iostream>
using namespace std;

int main()
{
    int n;
    int numbers[200]; // Maximum expected array size

    // Input size and array elements
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> numbers[i];

    // Step 1: Find index of maximum element
    int maximum_idx = 0;
    for (int i = 1; i < n; ++i)
        if (numbers[maximum_idx] < numbers[i])
            maximum_idx = i;

    int max1 = numbers[maximum_idx];

    // Temporarily replace max1 with a very small value
    numbers[maximum_idx] = -1000000;

    // Step 2: Find index of second maximum element
    maximum_idx = 0;
    for (int i = 1; i < n; ++i)
        if (numbers[maximum_idx] < numbers[i])
            maximum_idx = i;

    int max2 = numbers[maximum_idx];

    cout << max1 << " " << max2 << "\n";

    return 0;
}
