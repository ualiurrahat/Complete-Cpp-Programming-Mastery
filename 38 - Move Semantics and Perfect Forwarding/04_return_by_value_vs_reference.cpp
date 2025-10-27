// 04_return_by_value_vs_reference.cpp
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * @brief Compares returning by value (prvalue) vs by reference (lvalue).
 */
struct Employee
{
    int salary = 10;

    // Returns a copy → prvalue
    int get1() { return salary; }

    // Returns reference to member → lvalue
    int &get2() { return salary; }
};

/**
 * @brief Demonstrates how return type affects assignability.
 */
int main()
{
    Employee e;

    // get1() returns prvalue → cannot assign
    int s1 = e.get1();
    // e.get1() = 50;  // CE: prvalue not assignable

    // get2() returns lvalue reference → assignable
    int s2 = e.get2();
    int &s3 = e.get2(); // s3 is alias for e.salary
    s3 = 70;            // modifies e.salary
    e.get2() = 50;      // direct assignment via lvalue

    // std::max returns const lvalue reference to argument (in practice)
    const int &r = max(2, 3); // binds to temporary or argument

    cout << "Final salary: " << e.salary << endl;

    return 0;
}