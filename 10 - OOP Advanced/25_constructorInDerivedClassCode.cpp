/*
Problem Statement:

Demonstrate execution order of constructors in C++ with single, multiple, and virtual inheritance.

Cases:
1. Single Inheritance
   class B : public A
   - Execution order: A(), then B()

2. Multiple Inheritance
   class A : public B, public C
   - Execution order: B(), then C(), then A()

3. Virtual Inheritance
   class A : public B, virtual public C
   - Execution order: C(), then B(), then A()

@note
Time Complexity: O(1) for constructor calls
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

/**
 * @brief Base1 class with a constructor.
 */
class Base1
{
    int data1;

public:
    Base1(int i)
    {
        data1 = i;
        cout << "The Base1 constructor was called" << endl;
    }

    void printData1()
    {
        cout << "The value of data1 is " << data1 << endl;
    }
};

/**
 * @brief Base2 class with a constructor.
 */
class Base2
{
    int data2;

public:
    Base2(int i)
    {
        data2 = i;
        cout << "The Base2 constructor was called" << endl;
    }

    void printData2()
    {
        cout << "The value of data2 is " << data2 << endl;
    }
};

/**
 * @brief Derived class inheriting Base1 and Base2.
 * @details Demonstrates constructor initialization list and execution order.
 */
class Derived : public Base1, public Base2
{
    int derived1, derived2;

public:
    /// @brief Derived constructor initializes both base classes and its own members.
    Derived(int a, int b, int c, int d) : Base1(a), Base2(b), derived1(c), derived2(d)
    {
        cout << "Derived constructor was called" << endl;
    }

    void printDataDerived()
    {
        cout << "The value of derived1 is " << derived1 << endl;
        cout << "The value of derived2 is " << derived2 << endl;
    }
};

int main()
{
    // Demonstrating order of constructor calls
    Derived rahat(10, 20, 30, 40);

    // Show initialized values
    rahat.printData1();
    rahat.printData2();
    rahat.printDataDerived();

    return 0;
}
