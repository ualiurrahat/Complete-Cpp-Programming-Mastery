/**
 * @file 05_arrayOfObjects.cpp
 * @brief Demonstrates Array of Objects and Passing Objects in Functions.
 *
 * Array of Objects:
 * ------------------
 * - Similar to normal arrays, but stores objects instead of primitive data types.
 * - Each element of array represents an object of the class.
 *
 * Example:
 * - Employee class stores ID of multiple employees using an array of objects.
 */

#include <iostream>
using namespace std;

class Employee
{
    int id;     ///< Employee ID
    int salary; ///< Employee salary (default = 4500)

public:
    /// Reads employee ID
    void setID()
    {
        salary = 4500; // Assign a default salary
        cout << "Enter ID of employee: ";
        cin >> id;
    }

    /// Displays employee ID
    void getID()
    {
        cout << "Employee ID: " << id << " with Salary: " << salary << endl;
    }
};

int main()
{
    Employee office[100]; // Array of Employee objects

    // Input 4 employees
    for (int i = 0; i < 4; i++)
    {
        office[i].setID();
    }

    // Display 4 employees
    for (int i = 0; i < 4; i++)
    {
        office[i].getID();
    }

    return 0;
}
