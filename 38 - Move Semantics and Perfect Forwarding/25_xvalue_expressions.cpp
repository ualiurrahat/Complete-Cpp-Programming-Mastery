// 25_xvalue_expressions.cpp
#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

/**
 * @brief Examples of **xvalue** (eXpiring value) expressions.
 *
 * @details
 * - Has identity (like lvalue)
 * - But is movable (like prvalue)
 * - Created by: `std::move(x)`, `f() &&`, member access on rvalue, etc.
 */
void f1(int t) {}
int &&f2() { return 10; }

struct Employee
{
    string name;
};

int main()
{
    int x = 15;
    int &&xr = 15;

    // prvalue
    20;

    // xvalue: std::move(x)
    std::move(x);

    // xvalue: return type is rvalue ref
    f1(f2());

    // xvalue: member of rvalue
    string("mostafa")[1];
    Employee{}.name;

    // xvalue → rvalue ref
    (string &&)Employee{}.name;

    // CE: cannot cast prvalue to rvalue ref
    // (string&&)string("mostafa");

    return 0;
}