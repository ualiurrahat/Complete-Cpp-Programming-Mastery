/**
 * @file 03_storingRecords.cpp
 * @brief Demonstrates storing multiple student records in a file.
 *
 * This program takes name and age for 3 students and stores them in a file.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief Main function to store student records into a file.
 * @note Time Complexity: O(3) ≈ O(1) (constant number of records in this case).
 * @note Space Complexity: O(1)
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
