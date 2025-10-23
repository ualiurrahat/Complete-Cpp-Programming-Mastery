/**
 * @file 03_structEmployeeMethods.cpp
 * @brief Demonstrates defining member functions (methods) inside a structure.
 *
 * -------------------- Problem Statement --------------------
 * Improve the employee structure by:
 * 1. Moving read/print functionality inside the struct.
 * 2. Adding getter/setter for private-like data handling.
 * -----------------------------------------------------------
 */

#include <iostream>
using namespace std;

// ---------------------- Structure Definition ----------------------
struct employee
{
    string name;
    int age;
    double salary;
    char gender;

    // ---------------------- Member Functions ----------------------
    void read_employee()
    {
        cout << "Enter employee 4 entries: ";
        cin >> name >> age >> salary >> gender;
    }

    void print_employee()
    {
        cout << name << " has salary " << salary << "\n";
    }

    int get_age()
    {
        return age;
    }

    void set_age(int new_age)
    {
        age = new_age;
    }
};

// ---------------------- Global Variables ----------------------
const int MAX = 10000;
employee employees_arr[MAX];
int added = 0;

// ---------------------- Helper Function ----------------------
void print_employees()
{
    for (int i = 0; i < added; ++i)
        employees_arr[i].print_employee();
}

// ---------------------- Main Function ----------------------
int main()
{
    employees_arr[added++].read_employee();
    employees_arr[added++].read_employee();
    print_employees();

    return 0;
}

/*
-------------------- Example Input --------------------
Rahat 24 1500 F
Ali 28 2000 M

-------------------- Example Output --------------------
Rahat has salary 1500
Ali has salary 2000
*/
