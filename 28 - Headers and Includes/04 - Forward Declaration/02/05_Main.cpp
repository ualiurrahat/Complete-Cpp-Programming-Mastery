/**
 * @file 05_Main.cpp
 * @brief Demo: creates `Employee`s and `Department`, links them.
 *
 * @note Both headers are included.
 * @note Memory is manually managed (for learning).
 */

#include <iostream>
#include "01_EmployeeHeader.cpp"
#include "02_DepartmentHeader.cpp"
using namespace std;

int main()
{
    Employee e1("Mostafa");
    Employee e2("Ali");

    Department *dep = new Department();
    dep->name = "CS";
    dep->deps.push_back(e1);
    dep->deps.push_back(e2);

    // Link back
    e1.deps.push_back(dep);
    e2.deps.push_back(dep);

    // Print
    e1.Print();

    // Cleanup
    delete dep;
    delete emp_glob;
    emp_glob = nullptr;

    return 0;
}