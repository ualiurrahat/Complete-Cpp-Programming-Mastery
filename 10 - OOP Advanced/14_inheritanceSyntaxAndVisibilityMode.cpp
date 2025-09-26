/**
 * @file 14_inheritanceSyntaxAndVisibilityMode.cpp
 * @brief Demonstrates basic inheritance syntax and visibility modes in C++.
 *
 * Notes on inheritance:
 * 1. Default visibility mode for inheritance is private.
 * 2. public inheritance → public members of base remain public in derived.
 * 3. private inheritance → public members of base become private in derived.
 * 4. Private members of the base class are never inherited.
 */

#include <iostream>
#include <string>
using namespace std;

// -------------------- Base Class --------------------
class Employee
{
public:
    int id;
    float salary;

    Employee() {} // Default constructor
    Employee(int num)
    {
        id = num;
        salary = 2500; // fixed salary for all employees
    }
};

// -------------------- Derived Class --------------------
class Programmer : Employee
{ // default inheritance mode is private
public:
    Programmer(int num)
    {
        id = num; // can access public members in base, but inherited as private
    }
    int code = 9;

    void getID()
    {
        cout << "Programmer ID: " << id << endl;
    }
};

// ------------------------------- Main -------------------------------
int main()
{
    Employee harry(1), rahat(2);

    // Accessing salary of Employee objects directly
    cout << "Harry's salary: " << harry.salary << endl;
    cout << "Rahat's salary: " << rahat.salary << endl;

    Programmer murr(1);
    murr.getID(); // Can access id via derived class method

    return 0;
}
