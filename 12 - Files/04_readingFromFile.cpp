/**
 * @file 04_readingFromFile.cpp
 * @brief Demonstrates how to read data from a file line by line.
 *
 * This program reads and prints the content of "me.txt" using getline().
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief Main function to demonstrate reading from a file.
 * @note Time Complexity: O(n) where n is the number of lines in the file.
 * @note Space Complexity: O(1)
 */
int main()
{
    ifstream file("me.txt");
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;

    cout << "Contents of me.txt:" << endl;
    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
    return 0;
}
