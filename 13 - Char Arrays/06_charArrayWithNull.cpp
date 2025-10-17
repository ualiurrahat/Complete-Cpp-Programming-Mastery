/**
 * @file 06_charArrayWithNull.cpp
 * @brief Demonstrates proper use of null terminator in character arrays.
 */

#include <iostream>
using namespace std;

int main()
{
    char name1[5];
    name1[0] = 'H';
    name1[1] = 'a';
    name1[2] = 'n';
    name1[3] = 'i';
    name1[4] = '\0'; // Proper null character marks end of string

    // Prints correctly since '\0' stops printing
    cout << name1 << "\n";

    return 0;
}
