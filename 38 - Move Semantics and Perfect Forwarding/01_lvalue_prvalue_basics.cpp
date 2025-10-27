// 01_lvalue_prvalue_basics.cpp
#include <iostream>
using namespace std;

/**
 * @brief Demonstrates the fundamental difference between lvalues and prvalues.
 *
 * @details
 * - An **lvalue** has an identifiable memory address and can appear on the left of assignment.
 * - A **prvalue** ("pure rvalue") is a temporary value without identity — cannot be assigned to.
 * - Every variable name is an lvalue.
 * - Literals like 100 are prvalues.
 */
int main()
{
    int salary = 100; // 'salary' is lvalue, 100 is prvalue

    // salary: has address, modifiable → lvalue
    // 100: temporary, no address, not assignable → prvalue

    // Valid: assign to lvalue
    salary = 200;

    // Compilation Error: 200 is prvalue → no address to assign to
    // 200 = salary;

    cout << "Salary after assignment: " << salary << endl;

    return 0;
}