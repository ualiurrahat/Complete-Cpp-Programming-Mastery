/**
 * @file 02_structEmployeeReference.cpp
 * @brief Demonstrates passing structures by reference and modularizing I/O functions.
 *
 * -------------------- Problem Statement --------------------
 * Extend the previous employee structure program to:
 * 1. Use functions that receive and manipulate `employee` by reference.
 * 2. Keep an array of employees globally.
 * 3. Read and print employee data using helper functions.
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
};

// ---------------------- Global Variables ----------------------
const int MAX = 10000;
employee employees_arr[MAX];
int added = 0; // Number of employees added so far

// ---------------------- Function Definitions ----------------------

/**
 * @brief Reads a single employee record from user input.
 * @param e Reference to an employee struct (to modify the original directly)
 * @note Passing by reference avoids copying the whole struct.
 */
void read_employee(employee &e)
{
    cout << "Enter employee 4 entries: ";
    cin >> e.name >> e.age >> e.salary >> e.gender;
}

/**
 * @brief Prints one employee's basic info.
 */
void print_employee(employee &e)
{
    cout << e.name << " has salary " << e.salary << "\n";
}

/**
 * @brief Prints all stored employees by iterating the array.
 */
void print_employees()
{
    for (int i = 0; i < added; ++i)
        print_employee(employees_arr[i]);
}

// ---------------------- Main Function ----------------------
int main()
{
    // Read two employees and store them in global array
    read_employee(employees_arr[added++]);
    read_employee(employees_arr[added++]);

    // Print all employees
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
