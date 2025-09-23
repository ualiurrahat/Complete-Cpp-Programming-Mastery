/**
 * @file 01_structure.cpp
 * @brief Demonstrates use of structures in C++.
 *
 * Structures allow grouping of variables of different datatypes under one name.
 * Unlike arrays, structures can store mixed types.
 *
 * @note Time Complexity: O(1) (access)
 * @note Space Complexity: O(1) (per structure instance)
 */

#include <iostream>
using namespace std;

// Defining a structure
struct Employee
{
    int ID;
    char faveChar;
    float salary;
};

int main()
{
    // Declaring a structure variable
    Employee rishu;

    // Assigning values to members
    rishu.ID = 2345;
    rishu.faveChar = 'C';
    rishu.salary = 50000;

    cout << "Employee Details:" << endl;
    cout << "ID: " << rishu.ID << endl;
    cout << "Favorite Character: " << rishu.faveChar << endl;
    cout << "Salary: " << rishu.salary << endl;

    return 0;
}
