/**
 * @file 04_staticDataMemberAndFunction.cpp
 * @brief Demonstrates Static Data Members and Static Functions in C++.
 *
 * Static Data Members:
 * ---------------------
 * - Shared among all objects of the class (only one copy).
 * - Useful for keeping track of information common to all objects.
 *
 * Static Member Functions:
 * -------------------------
 * - Can only access static data members.
 * - Independent of objects (can be called using ClassName::FunctionName).
 *
 * Example:
 * - Employee class uses a static count variable to track number of employees.
 */

#include <iostream>
using namespace std;

class Employee
{
    int id;           ///< Employee ID (non-static, unique to each object)
    static int count; ///< Static variable to count employees

public:
    /// Reads employee ID from user
    void setData()
    {
        cout << "Enter employee ID: ";
        cin >> id;
        count++;
    }

    /// Displays employee ID with employee number
    void getData()
    {
        cout << "Employee no: " << count << " has ID: " << id << endl;
    }

    /// Static function to retrieve static variable count
    static void getCount()
    {
        cout << "Total employees so far: " << count << endl;
    }
};

// Define static data member (initialized to 0 by default)
int Employee::count;

int main()
{
    Employee e1, e2, e3;

    e1.setData();
    e1.getData();
    Employee::getCount();

    e2.setData();
    e2.getData();
    Employee::getCount();

    e3.setData();
    e3.getData();
    Employee::getCount();

    return 0;
}
