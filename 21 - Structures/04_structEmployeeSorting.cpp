/**
 * @file 04_structEmployeeSorting.cpp
 * @brief Demonstrates sorting of structures using custom comparator functions.
 *
 * -------------------- Problem Statement --------------------
 * 1. Define employee structure with name, age, salary, and gender.
 * 2. Read multiple employees into an array.
 * 3. Sort employees based on name, salary, and a combination of both.
 * 4. Use C++ STL sort() function with custom comparison functions.
 * -----------------------------------------------------------
 */

#include <iostream>
#include <algorithm> // for sort()
using namespace std;

// ---------------------- Structure Definition ----------------------
struct employee
{
    string name;
    int age;
    double salary;
    char gender;

    void read_employee()
    {
        cout << "Enter employee 4 entries: ";
        cin >> name >> age >> salary >> gender;
    }

    void print_employee()
    {
        cout << name << " has salary " << salary << "\n";
    }
};

// ---------------------- Global Variables ----------------------
const int MAX = 10000;
employee employees_arr[MAX];
int added = 0;

// ---------------------- Helper Functions ----------------------
void print_employees()
{
    cout << "******************\n";
    for (int i = 0; i < added; ++i)
        employees_arr[i].print_employee();
}

// Comparison functions used by sort()

bool compare_name(employee &a, employee &b)
{
    return a.name < b.name; // Ascending by name
}

bool compare_salary(employee &a, employee &b)
{
    return a.salary > b.salary; // Descending by salary
}

bool compare_name_salary(employee &a, employee &b)
{
    if (a.name != b.name)
        return a.name < b.name; // Ascending by name
    return a.salary < b.salary; // If names equal, ascending salary
}

// ---------------------- Main Function ----------------------
int main()
{
    // Demonstrate sorting of primitive array
    int arr[5] = {5, 1, 3, 2, 4};
    sort(arr, arr + 5);
    for (int i = 0; i < 5; ++i)
        cout << arr[i] << " ";
    cout << "\n";

    // Read employees
    employees_arr[added++].read_employee();
    employees_arr[added++].read_employee();
    employees_arr[added++].read_employee();

    // Sort by different criteria
    sort(employees_arr, employees_arr + added, compare_name);
    print_employees();

    sort(employees_arr, employees_arr + added, compare_salary);
    print_employees();

    sort(employees_arr, employees_arr + added, compare_name_salary);
    print_employees();

    return 0;
}

/*
-------------------- Example Input --------------------
Rahat 24 1500 F
Ali 28 2000 M
Bithi 22 1200 F

-------------------- Example Output --------------------
******************
Ali has salary 2000
Bithi has salary 1200
Rahat has salary 1500
******************
Rahat has salary 1500
Ali has salary 2000
Bithi has salary 1200
******************
Ali has salary 2000
Bithi has salary 1200
Rahat has salary 1500
*/
