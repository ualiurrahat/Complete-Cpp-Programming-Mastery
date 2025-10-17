/**
 * @file 09_arrayOfNames.cpp
 * @brief Demonstrates storing and printing multiple names using a string array.
 *
 * Problem Statement:
 * Create an array of 5 strings and print them line by line.
 */

#include <iostream>
using namespace std;

int main()
{
    // Array of names - some positions initialized, others will be empty strings
    string names[5] = {"Mostafa Saad", "Never Ever", "Hello world"};

    // Print all 5 names (last two will print blank lines)
    for (int index = 0; index < 5; ++index)
        cout << names[index] << "\n";

    return 0;
}

/**
 * @example
 * Output:
 * Mostafa Saad
 * Never Ever
 * Hello world
 *
 *
 */
