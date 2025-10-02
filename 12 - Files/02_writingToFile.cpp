/**
 * @file 02_writingToFile.cpp
 * @brief Demonstrates how to write and append data to a file in C++.
 *
 * This example shows how to open a file in `ios::app` mode,
 * write predefined text and also take user input to store in the file.
 */

#include <iostream>
#include <fstream> // For file handling
#include <string>  // For getline input

using namespace std;

/**
 * @brief Main function to demonstrate writing to a file.
 * @note Time Complexity: O(n) where n is length of written data.
 * @note Space Complexity: O(1)
 */
int main()
{
    string profession;

    // Create an ofstream object to write to file in append mode.
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
