/**
 * Problem: Find the minimum element in a 1D array.
 *
 * Concepts:
 * - Traverse the array to compare elements
 * - Keep track of minimum value
 */

#include <iostream>
using namespace std;

int main()
{
    const int size = 5;

    // Declare an array of 5 integers
    int numbers[size];

    // Input array elements from user
    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; ++i)
        cin >> numbers[i];

    // Initialize minimum with first element
    int minimum = numbers[0];

    // Traverse remaining elements to find minimum
    for (int i = 1; i < size; ++i)
    {
        if (numbers[i] < minimum)
        {
            minimum = numbers[i];
        }
    }

    cout << "Minimum element: " << minimum << "\n";

    return 0;
}
