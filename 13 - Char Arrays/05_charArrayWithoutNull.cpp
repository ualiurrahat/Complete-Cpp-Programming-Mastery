/**
 * @file 05_charArrayWithoutNull.cpp
 * @brief Demonstrates what happens when char array is missing null terminator.
 */

#include <iostream>
using namespace std;

int main()
{
    char name1[4];
    name1[0] = 'H';
    name1[1] = 'a';
    name1[2] = 'n';
    name1[3] = 'i'; // No null terminator '\0'

    // Undefined behavior — may print extra garbage characters
    cout << name1 << "\n";

    return 0;
}
