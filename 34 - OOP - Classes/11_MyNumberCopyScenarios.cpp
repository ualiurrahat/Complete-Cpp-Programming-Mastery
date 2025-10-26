/**
 * @file 11_MyNumberCopyScenarios.cpp
 * @brief Shows **all scenarios** that trigger copy constructor.
 *
 * Copy constructor is called in:
 * 1. `MyNumber c(b);`           – copy initialization
 * 2. `MyNumber d = b;`          – same as above (not assignment)
 * 3. Pass by value: `fun1(c)`   – copy into parameter
 * 4. Return by value: `fun2()`  – copy return value (often elided by RVO)
 *
 * **Assignment** `a = b;` → does **not** call copy constructor
 */

#include <iostream>
#include <vector>
using namespace std;

class MyNumber
{
private:
    int *val1;
    int val2;

public:
    MyNumber(int x = 3, int y = 5)
    {
        val1 = new int;
        *val1 = x;
        val2 = y;
        cout << "Normal constructor\n";
    }

    ~MyNumber()
    {
        delete val1;
    }

    void PrintValueAndAddress() const
    {
        cout << "val1: " << *val1 << " @ " << val1 << "\n";
        cout << "val2: " << val2 << " @ " << &val2 << "\n\n";
    }
};

void fun1(MyNumber x)
{ // copy ctor
    cout << "Inside fun1\n";
}

MyNumber fun2()
{
    MyNumber e(1, 2);
    cout << "fun2: creating return object\n";
    return e; // copy ctor (often optimized away by RVO)
}

int main()
{
    MyNumber a;
    MyNumber b(10, 20);

    MyNumber c(b);  // copy ctor
    MyNumber d = b; // copy ctor (initialization)

    fun1(c); // copy ctor
    fun2();  // copy ctor (may be elided)

    a = b; // assignment operator (NOT copy ctor)

    a.PrintValueAndAddress();
    b.PrintValueAndAddress();
    c.PrintValueAndAddress();
    d.PrintValueAndAddress();

    return 0;
}