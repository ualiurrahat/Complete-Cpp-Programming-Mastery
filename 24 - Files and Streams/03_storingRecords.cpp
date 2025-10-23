/**
 * @file 03_storingRecords.cpp
 * @brief Demonstrates storing multiple student records in a file.
 *
 * This file shows how to collect and store structured data (name and age) in a file using a tabular format.
 *
 * New Topics Introduced:
 * - **Tabular Data Storage**: Using tabs (`\t`) to separate fields in a file for structured data.
 * - **cin.ignore()**: Syntax: `cin.ignore()`. Clears the input buffer after reading a number to prevent issues with subsequent `getline`.
 * - **Use Case**: Storing records in a file is useful for databases or data logging applications.
 *
 * The program collects name and age for 3 students and stores them in a file.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
 * @brief Main function to store student records into a file.
 * @note Time Complexity: O(1) for fixed number of records (3 in this case).
 * @note Space Complexity: O(1) for fixed-size inputs.
 * @return int Program exit status.
 */
int main()
{
    ofstream file("student.txt", ios::out | ios::app);

    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string name;
    int age;

    for (int i = 1; i <= 3; i++)
    {
        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter age: ";
        cin >> age;
        cin.ignore(); // Clear input buffer

        // Store name and age in tabular format
        file << name << "\t" << age << endl;
    }

    file.close();
    cout << "Student records saved successfully in student.txt\n";

    return 0;
}