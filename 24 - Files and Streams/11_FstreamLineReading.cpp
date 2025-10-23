/**
 * @file 11_FstreamLineReading.cpp
 * @brief Demonstrates reading lines from a file using fstream and getline.
 *
 * This file uses `fstream` to read all lines from a file, similar to `ifstream` but demonstrating `fstream`’s versatility.
 *
 * New Topics Introduced:
 * - **getline with fstream**: Syntax: `getline(fstream& fs, string& s)`. Reads a line from an `fstream` object, useful for text processing.
 * - **Use Case**: `fstream` can be used for reading when write access might be needed later, providing flexibility.
 *
 * The program reads and prints all lines from "names.txt" using `fstream`.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * @brief Main function to read lines from a file using fstream.
 * @note Time Complexity: O(n) where n is the number of lines read.
 * @note Space Complexity: O(n) for storing each line.
 * @return int Program exit status.
 */
int main() {
    string path = "names.txt";
    fstream file_handler(path.c_str()); // Open file (default mode: ios::in | ios::out)

    if (file_handler.fail()) {
        cout << "Can't open the file\n";
        return 0;
    }

    string line;
    while (getline(file_handler, line)) { // Read each line
        cout << line << "\n";
    }

    file_handler.close();
    return 0;
}