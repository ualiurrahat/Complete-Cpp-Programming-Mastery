/**
 * @file 10_FstreamReadWrite.cpp
 * @brief Demonstrates simultaneous reading and writing using fstream.
 *
 * This file introduces the `fstream` class for combined read/write file operations and dynamic mode selection.
 *
 * New Topics Introduced:
 * - **fstream Class**: Syntax: `fstream(filename, ios::openmode)`. Allows both reading and writing to a file. Modes include `ios::in`, `ios::out`, `ios::app` (append), `ios::trunc` (truncate).
 * - **clear() Function**: Syntax: `void clear()`. Resets the stream’s error state (e.g., after a failed read) to allow further operations like writing.
 * - **Use Case**: `fstream` is useful for updating files (e.g., modifying existing data) or logging with read-back verification.
 *
 * The program reads two strings from a file, prints them, and appends a new string, switching between read and write modes.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * @brief Main function to demonstrate reading and writing with fstream.
 * @note Time Complexity: O(n) where n is the size of data read/written.
 * @note Space Complexity: O(n) for storing strings.
 * @return int Program exit status.
 */
int main() {
    bool append = true;
    auto status = ios::in | ios::out | ios::app; // Default: append mode
    if (!append) {
        status = ios::in | ios::out | ios::trunc; // Overwrite mode
    }

    string path = "names.txt";
    fstream file_handler(path.c_str(), status); // Open file for read/write

    if (file_handler.fail()) {
        cout << "Can't open the file\n";
        return 0;
    }

    string first, second;
    file_handler >> first >> second; // Read two strings
    cout << first << " " << second << "\n";

    file_handler.clear(); // Clear error state before writing
    file_handler << "\nibrahim\n"; // Append new string

    file_handler.close();
    return 0;
}