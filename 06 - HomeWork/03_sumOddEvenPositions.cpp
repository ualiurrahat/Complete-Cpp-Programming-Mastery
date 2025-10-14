/**
 * @file 03_sumOddEvenPositions.cpp
 * @brief Reads 8 integers and calculates the sum of numbers in odd and even positions.
 *
 * @details
 * - Odd positions: 1st, 3rd, 5th, 7th numbers.
 * - Even positions: 2nd, 4th, 6th, 8th numbers.
 * - Demonstrates structured reading of multiple inputs and variable naming for clarity.
 * - Helps beginners understand indexing logic without using arrays.
 */

#include <iostream>
using namespace std;

int main()
{
    // Declare variables for odd and even positions
    int odd1, odd2, odd3, odd4;
    int even1, even2, even3, even4;

    // Read numbers in order: odd then even
    cin >> odd1 >> even1;
    cin >> odd2 >> even2;
    cin >> odd3 >> even3;
    cin >> odd4 >> even4;

    // Calculate sums
    int odd_sum = odd1 + odd2 + odd3 + odd4;
    int even_sum = even1 + even2 + even3 + even4;

    // Display sums
    cout << even_sum << " " << odd_sum << "\n";

    return 0;
}

/*
Example input:
11 2 7 9 12 -8 3 -1

Expected output:
2 33
*/
