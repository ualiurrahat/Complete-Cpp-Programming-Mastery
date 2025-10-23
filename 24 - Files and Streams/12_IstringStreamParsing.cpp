/**
 * @file 12_IstringStreamParsing.cpp
 * @brief Demonstrates parsing a string using istringstream.
 *
 * This file introduces string streams for parsing data from a string instead of a file.
 *
 * New Topics Introduced:
 * - **istringstream Class**: Syntax: `istringstream(string s)`. Treats a string as an input stream, allowing extraction with `>>` or `getline`.
 * - **Use Case**: Useful for parsing formatted strings (e.g., CSV data, user input) without writing to a file.
 *
 * The program parses a string containing a name and age, extracting them into separate variables.
 */

#include <iostream>
#include <sstream>
using namespace std;

/**
 * @brief Main function to demonstrate parsing with istringstream.
 * @note Time Complexity: O(n) where n is the length of the string.
 * @note Space Complexity: O(n) for storing the string and variables.
 * @return int Program exit status.
 */
int main() {
    string str = "Mostafa 23 years";
    istringstream iss(str); // Create input string stream

    string name;
    int age;
    iss >> name >> age; // Extract name and age

    cout << age << "\n"; // Output the age
    return 0;
}