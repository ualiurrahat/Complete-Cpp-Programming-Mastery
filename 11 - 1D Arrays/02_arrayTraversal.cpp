/**
 * Problem: Demonstrate array traversal and reverse traversal.
 * - Print array elements in order
 * - Print array elements in reverse
 *
 * Concepts:
 * - Use loops to access all elements
 * - Array indices start from 0 up to size-1
 */

#include <iostream>
using namespace std;

int main()
{
    const int size = 5;

    // Declare and initialize array
    int numbers[size] = {1, 2, 3, 4, 5};

    // Forward traversal
    for (int i = 0; i < size; ++i)
        cout << numbers[i] << " ";
    cout << "\n";

    // Reverse traversal
    for (int i = 0; i < size; ++i)
        cout << numbers[size - i - 1] << " ";
    cout << "\n";

    return 0;
}
