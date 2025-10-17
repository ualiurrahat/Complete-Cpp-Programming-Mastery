/**
 * @file 10_inputArrayOfNames.cpp
 * @brief Demonstrates taking multiple names as input using a string array.
 *
 * Problem Statement:
 * Input 2 names (without spaces) and store them in an array, then print them.
 */

#include <iostream>
using namespace std;

int main()
{
    string names[2]; // Array of 2 strings

    // Input two names from the user
    for (int index = 0; index < 2; ++index)
        cin >> names[index];

    // Output the names
    for (int index = 0; index < 2; ++index)
        cout << names[index] << "\n";

    return 0;
}

/**
 * @example
 * Input:
 * Rahat
 * Ualiur
 *
 * Output:
 * Rahat
 * Ualiur
 */
