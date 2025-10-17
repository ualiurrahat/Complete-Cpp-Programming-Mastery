/**
 * @file 07_nullCharacterInsideArray.cpp
 * @brief Demonstrates effect of placing null character ('\0') inside array.
 */

#include <iostream>
using namespace std;

int main()
{
    char name1[5];
    name1[0] = 'H';
    name1[1] = '\0'; // Stops printing at this point
    name1[2] = 'n';
    name1[3] = 'i';
    name1[4] = '\0'; // Final null character

    // Will only print up to first '\0'
    cout << name1 << "\n"; // Output: H

    return 0;
}
