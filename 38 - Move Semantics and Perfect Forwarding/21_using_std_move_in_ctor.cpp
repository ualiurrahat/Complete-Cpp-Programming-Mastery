// 21_using_std_move_in_ctor.cpp
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/**
 * @brief Uses `std::move` to enable move in constructor.
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
    Department(Employee &&etemp) : e(std::move(etemp)) {} // Force move
    Department(Employee &etemp) : e(etemp) {}             // Copy
};

int main()
{
    Employee e1;
    Department d1(e1);         // copy
    Department d2(Employee{}); // move: temporary → moved into e

    return 0;
}