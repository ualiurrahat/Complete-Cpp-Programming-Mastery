/**
 * @file 05_openAndEOF.cpp
 * @brief Demonstrates using open() and eof() functions in file handling.
 *
 * This program writes data to a file, then reads it back using eof() in a loop.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief Main function to demonstrate open() and eof() usage.
 * @note Time Complexity: O(n) where n is number of lines read.
 * @note Space Complexity: O(1)
 */
int main()
{
    // Writing into a file using open()
    ofstream out;
    out.open("sample62.txt");

    if (!out)
    {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    out << "This is file for tutorial 62" << endl;
    out << "I am trying to learn" << endl;
    out << "Reading and writing using file" << endl;
    out.close();

    // Now read from same file
    ifstream in;
    in.open("sample62.txt");

    if (!in)
    {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    string line;
    cout << "Contents of sample62.txt:" << endl;

    // Read file until end-of-file is reached
    while (in.eof() == 0)
    {
        getline(in, line);
        cout << line << endl;
    }

    in.close();
    return 0;
}
