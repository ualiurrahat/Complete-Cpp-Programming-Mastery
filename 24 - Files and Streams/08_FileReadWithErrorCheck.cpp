/**
 * @file 08_FileReadWithErrorCheck.cpp
 * @brief Demonstrates reading from a file with error checking using ifstream.
 *
 * This file introduces error checking for file operations using the `fail()` function.
 *
 * New Topics Introduced:
 * - **fail() Function**: Syntax: `bool fail()`. Returns true if a stream operation fails (e.g., file not found, invalid format). Useful for robust error handling.
 * - **Use Case**: Checking `fail()` ensures the program handles file opening errors gracefully, preventing crashes or undefined behavior.
 *
 * The program reads two integers from a file, checks for file opening errors, and outputs their sum.
 */

#include <iostream>
#include <fstream>
using namespace std;

/**
 * @brief Main function to read integers from a file with error checking.
 * @note Time Complexity: O(1) for reading two integers and computing their sum.
 * @note Space Complexity: O(1) for fixed-size variables.
 * @return int Program exit status.
 */
int main() {
    ifstream fin("read_file.txt"); // Open file for reading

    if (fin.fail()) {
        cout << "Can't open the file\n";
        return 0;
    }

    int x, y;
    fin >> x >> y; // Read two integers
    cout << x + y; // Output their sum

    fin.close(); // Close the file
    return 0;
}