/**
 * @file pointerArithmetic.cpp
 * @brief Demonstrates pointer arithmetic in C++.
 *
 * Pointer arithmetic depends on the size of the datatype:
 * - If int = 4 bytes, then ptr+1 = current address + 4
 * - *(ptr + i) accesses ith element in an array
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

int main()
{
    int scienceMarks[] = {44, 45, 46, 48};
    int *ptr = scienceMarks; // points to first element of array

    cout << "Science Marks using pointer arithmetic:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << *(ptr + i) << endl;
    }

    return 0;
}
