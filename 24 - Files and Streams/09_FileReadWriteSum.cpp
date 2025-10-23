/**
 * @file 09_FileReadWriteSum.cpp
 * @brief Demonstrates reading integers from one file and writing their sum to another.
 *
 * This file combines reading and writing operations, with error checking for both input and output files.
 *
 * New Topics Introduced:
 * - **Combined File I/O**: Using `ifstream` for reading and `ofstream` for writing in the same program.
 * - **Error Checking for Output**: Applying `fail()` to output streams to ensure the output file is accessible.
 * - **Use Case**: Useful for processing data from one file and storing results in another, such as in data processing pipelines.
 *
 * The program reads two integers from "read_file.txt", computes their sum, and writes it to "my_output.txt".
 */

#include <iostream>
#include <fstream>
using namespace std;

/**
 * @brief Main function to read integers from one file and write their sum to another.
 * @note Time Complexity: O(1) for reading and writing fixed-size data.
 * @note Space Complexity: O(1) for fixed-size variables.
 * @return int Program exit status.
 */
int main() {
    ifstream fin("read_file.txt"); // Open input file

    if (fin.fail()) {
        cout << "Can't open the input file\n";
        return 0;
    }

    int x, y;
    fin >> x >> y; // Read two integers
    fin.close();

    ofstream fout("my_output.txt"); // Open output file

    if (fout.fail()) {
        cout << "Can't open the output file\n";
        return 0;
    }

    fout << x + y; // Write sum to file
    fout.close();

    return 0;
}