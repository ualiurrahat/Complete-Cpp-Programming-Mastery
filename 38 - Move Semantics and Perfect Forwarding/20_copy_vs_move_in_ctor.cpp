// 20_copy_vs_move_in_ctor.cpp
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/**
 * @brief Shows how constructor parameters affect copy/move.
 */
class Employee
{
public:
    Employee() = default;
    Employee(const Employee &) { cout << "Copy\n"; }
    Employee(Employee &&) { cout << "Move\n"; }
};

class Department
{
private:
    Employee e;

public:
    // Both ctors take by value → always copy
    Department(Employee &&etemp) : e(etemp) {} // etemp is lvalue → copy
    Department(Employee &etemp) : e(etemp) {}  // lvalue → copy
};

int main()
{
    Employee e1;
    Department d1(e1);         // copy: e1 is lvalue
    Department d2(Employee{}); // copy: Employee{} is prvalue → but etemp is lvalue in ctor

    return 0;
}