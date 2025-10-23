/**
 * @file 01_workingWithFiles.cpp
 * @brief Demonstration of File Handling in C++.
 *
 * This file introduces basic file handling using `ofstream` for writing and `ifstream` for reading.
 *
 * New Topics Introduced:
 * - **File Streams**: `<fstream>` provides `ofstream` for writing and `ifstream` for reading files.
 * - **Constructor-Based File Opening**: Files can be opened directly via `ofstream` or `ifstream` constructors.
 * - **getline Function**: Syntax: `getline(istream& in, string& s)`. Reads a line from an input stream into a string. Useful for reading text line by line.
 * - **Use Case**: File I/O is used to persist data (e.g., logs, user data) or read configuration files.
 *
 * The program writes a string to a file and reads from another file, demonstrating both word-by-word and line-by-line reading.
 */

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Main function demonstrating writing and reading files in C++.
 * @note Time Complexity: O(n) where n is the size of data read/written.
 * @note Space Complexity: O(n) for storing strings.
 * @return int Program exit status.
 */
int main()
{
    // -------------------- Writing to a File --------------------
    ofstream out("sample.txt"); // Open file using constructor
    string name = "I am Md. Ualiur Rahman Rahat";

    out << name; // Write content to file
    out.close(); // Close file after writing

    cout << "Data written to 'sample.txt'.\n";

    // -------------------- Reading from a File --------------------
    ifstream in("sample_59.txt"); // Open file using constructor
    string s;

    // Reading first word from file
    in >> s;
    cout << "First word from file: " << s << endl;

    // Reading line by line using getline
    getline(in, s);
    cout << "Line 1: " << s << endl;

    getline(in, s);
    cout << "Line 2: " << s << endl;

    in.close(); // Close file after reading

    return 0;
}