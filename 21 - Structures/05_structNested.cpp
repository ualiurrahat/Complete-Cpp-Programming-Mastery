/**
 * @file 05_structNested.cpp
 * @brief Demonstrates nested structures (struct within struct).
 *
 * -------------------- Problem Statement --------------------
 * Create a structure `full_name` to store first, middle, and last names.
 * Then create an `employee` struct that includes `full_name` as a member.
 * -----------------------------------------------------------
 */

#include <iostream>
using namespace std;

// ---------------------- Structure Definitions ----------------------

struct full_name
{
    string first, middle, last;

    void read()
    {
        cout << "Enter first middle last names: ";
        cin >> first >> middle >> last;
    }
};

struct employee
{
    full_name emp_name;
    int age;
    double salary;

    void read()
    {
        emp_name.read();
        cout << "Enter employee age & salary: ";
        cin >> age >> salary;
    }

    void print()
    {
        cout << emp_name.first << " has salary " << salary << "\n";
    }
};

// ---------------------- Main Function ----------------------
int main()
{
    employee emp;
    emp.read();
    emp.print();
    return 0;
}
