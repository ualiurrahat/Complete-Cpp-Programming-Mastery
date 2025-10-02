/**
 * @file 01_workingWithFiles.cpp
 * @brief Demonstration of File Handling in C++.
 *
 * - A file is a collection of data stored on disk.
 * - Operations on files:
 *      1. Write (output to file)
 *      2. Read (input from file)
 *
 * Useful classes in <fstream>:
 * - fstreambase
 * - ifstream  → for reading
 * - ofstream  → for writing
 *
 * Two ways to open files:
 * 1. Using constructors
 * 2. Using the `open()` member function
 */

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Main function demonstrating writing and reading files in C++.
 */
int main()
{
    // -------------------- Writing to a File --------------------
    ofstream out("sample.txt"); // open file using constructor
    string name = "I am Md. Ualiur Rahman Rahat";

    out << name; // write content to file
    out.close(); // close file after writing

    cout << "Data written to 'sample.txt'.\n";

    // -------------------- Reading from a File --------------------
    ifstream in("sample_59.txt"); // open file using constructor
    string s;

    // Reading first word from file
    in >> s;
    cout << "First word from file: " << s << endl;

    // Reading line by line using getline
    getline(in, s);
    cout << "Line 1: " << s << endl;

    getline(in, s);
    cout << "Line 2: " << s << endl;

    in.close(); // close file after reading

    return 0;
}
