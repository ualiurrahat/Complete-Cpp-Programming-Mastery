/**
 * Problem: Find the two largest numbers in an array using a better approach.
 *
 * Concepts:
 * - Avoid repeated traversal of the array.
 * - Keep track of both maximum and second maximum in a single traversal.
 * - This improves efficiency compared to brute-force.
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

    // Initialize first two elements as max1 and max2
    int max1, max2;
    if (numbers[0] >= numbers[1])
    {
        max1 = numbers[0];
        max2 = numbers[1];
    }
    else
    {
        max1 = numbers[1];
        max2 = numbers[0];
    }

    // Traverse the rest of the array
    for (int i = 2; i < n; ++i)
    {
        if (numbers[i] >= max1)
        {
            max2 = max1;
            max1 = numbers[i];
        }
        else if (numbers[i] > max2)
        {
            max2 = numbers[i];
        }
    }

    cout << max1 << " " << max2 << "\n";

    return 0;
}
