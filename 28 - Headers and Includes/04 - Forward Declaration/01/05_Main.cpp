/**
 * @file 05_Main.cpp
 * @brief Demo program using the global `Employee`.
 *
 * @note Only `Employee.h` is needed; `Department` is pulled in via forward declaration.
 */

#include <iostream>
#include "01_EmployeeHeader.cpp"
using namespace std;

int main()
{
    emp_glob->Print();
    // Output:
    // I am mostafa
    // I work in the following departments:

    delete emp_glob; // Don't forget cleanup!
    emp_glob = nullptr;
    return 0;
}