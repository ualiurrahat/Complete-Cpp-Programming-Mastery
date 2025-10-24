/**
 * @file 03_array.cpp
 * @brief Demonstrates arrays in C++.
 *
 * Arrays are fixed-size collections of elements of the same type stored contiguously in memory.
 * - Accessed via index (0-based).
 * - Elements can be reassigned.
 * - If not initialized, contain garbage values.
 *
 * @note Time Complexity (Access): O(1)
 * @note Space Complexity: O(n) for array size
 */

#include <iostream>
using namespace std;

int main()
{
    // Declaring an array with fixed size
    int mathsMarks[4];
    mathsMarks[0] = 56;
    mathsMarks[1] = 54;
    mathsMarks[2] = 58;
    mathsMarks[3] = 57;

    cout << "Maths Marks:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << mathsMarks[i] << endl;
    }

    // Array initialization with values
    int scienceMarks[] = {44, 45, 46, 48};
    cout << "\nScience Marks:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << scienceMarks[i] << endl;
    }

    // Modifying array element
    scienceMarks[2] = 47;
    cout << "Modified Science Marks[2]: " << scienceMarks[2] << endl;

    // Empty array with default initialization
    int n = 4;
    int englishMarks[n] = {}; // all initialized to 0
    cout << "\nEnglish Marks:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << englishMarks[i] << endl; // will print 0 for all
    }

    return 0;
}
