/**
 * @file 02_studentGrades.cpp
 * @brief Reads information of 2 students and prints their grades and average.
 *
 * @details
 * - Demonstrates multiple data types: string for name/id, double for grade.
 * - Ensures proper handling of decimal grades.
 * - Demonstrates using parentheses for correct arithmetic evaluation.
 */

#include <iostream>
using namespace std;

int main()
{
    // Student 1 information
    string name1;
    cout << "What is student 1 name: ";
    cin >> name1;

    string id1;
    cout << "His id: ";
    cin >> id1;

    double grade1;
    cout << "His math exam grade: ";
    cin >> grade1;

    // Student 2 information
    string name2;
    cout << "What is student 2 name: ";
    cin >> name2;

    string id2;
    cout << "His id: ";
    cin >> id2;

    double grade2;
    cout << "His math exam grade: ";
    cin >> grade2;

    // Display grades and average
    cout << "\nStudents grades in math\n";
    cout << name1 << " (with id " << id1 << ") got grade: " << grade1 << "\n";
    cout << name2 << " (with id " << id2 << ") got grade: " << grade2 << "\n";

    double average = (grade1 + grade2) / 2.0; // parentheses ensure correct calculation
    cout << "Average grade is " << average << "\n";

    return 0;
}
