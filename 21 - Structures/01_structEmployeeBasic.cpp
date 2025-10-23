/**
 * @file 01_structEmployeeBasic.cpp
 * @brief Demonstrates basic use of structures (struct) in C++
 *
 * -------------------- Problem Statement --------------------
 * Create a program that stores information about employees using `struct`.
 * Each employee should have a name, age, salary, and gender.
 *
 * Tasks:
 * 1. Define a structure named `employee` to hold the above data.
 * 2. Create a global array to store multiple employees.
 * 3. Implement functions to read and print employee information.
 * 4. Demonstrate usage in `main()`.
 *
 * -----------------------------------------------------------
 * @note This program explains the basics of structures in C++
 */

#include <iostream>
using namespace std;

// ---------------------- Structure Definition ----------------------
/*
   A structure (struct) allows us to group multiple related variables
   of different types under a single name. This helps in representing
   a real-world entity like "Employee" in a structured way.
*/
struct employee
{
    string name;   // Employee's name
    int age;       // Employee's age
    double salary; // Employee's salary
    char gender;   // Employee's gender ('M' or 'F')
};

// ---------------------- Global Variables ----------------------
/*
   We can create an array of 'employee' to hold data for multiple employees.
   Using a global array allows all functions to access it.
*/
const int MAX = 10000; // Maximum possible number of employees
employee employees_arr[MAX];
int added = 0; // Keeps track of how many employees are added so far

// ---------------------- Function Declarations ----------------------

/**
 * @brief Reads employee data and stores it in the next available position.
 * @note Input format: name age salary gender
 */
void read_employee()
{
    cout << "Enter employee 4 entries: ";
    cin >> employees_arr[added].name >> employees_arr[added].age >> employees_arr[added].salary >> employees_arr[added].gender;

    // After reading data, increment 'added' to mark the new employee
    added++;
}

/**
 * @brief Prints all stored employees with their salaries.
 * @note Demonstrates accessing struct members using the dot operator.
 */
void print_employees()
{
    for (int i = 0; i < added; ++i)
    {
        // Copying the employee for readability
        employee e = employees_arr[i];
        cout << e.name << " has salary " << e.salary << "\n";
    }
}

// ---------------------- Main Function ----------------------
int main()
{
    /*
       We can assign structure members directly using initialization lists.
       Example: employee first = {"mostafa", 10, 1200.5, 'M'};
    */
    employee first = {"mostafa", 10, 1200.5, 'M'};
    employees_arr[added++] = first; // Store in array and increase count

    // Direct member assignment using the dot operator
    employees_arr[added].name = "hani";
    employees_arr[added].age = 55;
    employees_arr[added].salary = 750;
    employees_arr[added].gender = 'M';
    added++;

    // Function call to read and print
    read_employee();
    print_employees();

    return 0;
}

/*
-------------------- Example Input --------------------
Rahat 24 1500 F

-------------------- Example Output --------------------
mostafa has salary 1200.5
hani has salary 750
Rahat has salary 1500
*/
