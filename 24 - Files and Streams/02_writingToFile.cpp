/**
 * @file 02_writingToFile.cpp
 * @brief Demonstrates how to write and append data to a file in C++.
 *
 * This file shows how to open a file in append mode and write both predefined and user-input data.
 *
 * New Topics Introduced:
 * - **Append Mode**: Using `ios::app` flag to append data to a file instead of overwriting it.
 * - **File Error Checking**: Checking if a file opened successfully using `if (!file)`.
 * - **getline for User Input**: Syntax: `getline(cin, string& s)`. Reads a full line from standard input, useful for strings with spaces.
 * - **Use Case**: Append mode is useful for logging or adding data to existing files without losing previous content.
 *
 * The program writes a greeting and user-entered profession to a file.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * @brief Main function to demonstrate writing to a file.
 * @note Time Complexity: O(n) where n is length of written data.
 * @note Space Complexity: O(n) for storing the input string.
 * @return int Program exit status.
 */
int main()
{
    string profession;

    // Create an ofstream object to write to file in append mode
    ofstream file("me.txt", ios::out | ios::app);

    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Write predefined text into the file
    file << "Assalamu Alaikum. I am UR.\n";

    // Take input from user
    cout << "Enter your profession: ";
    getline(cin, profession);

    // Append user input into the file
    file << "Profession: " << profession << endl;

    file.close(); // Close the file

    cout << "Data written successfully to me.txt\n";
    return 0;
}