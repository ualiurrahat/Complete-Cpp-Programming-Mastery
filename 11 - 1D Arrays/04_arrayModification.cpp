/**
 * Problem: Demonstrate basic operations on a 1D array.
 * - Accessing array elements
 * - Modifying elements
 * - Incrementing elements
 * - Printing elements
 *
 * Concepts:
 * 1D arrays are collections of elements of the same type stored in contiguous memory.
 * Elements are accessed using indices starting from 0.
 */

#include <iostream>
using namespace std;

int main()
{
    const int size = 5; // Size of the array

    // Declare an array of 5 integers and initialize with values
    int numbers[size] = {10, 2, 7, 5, 3};

    // Modify array elements
    numbers[0] = 9;  // Set first element to 9
    numbers[2] *= 3; // Multiply third element by 3
    numbers[4]++;    // Increment last element by 1

    // Print the last element after modification
    cout << numbers[4] << "\n"; // Output: 4

    return 0;
}
