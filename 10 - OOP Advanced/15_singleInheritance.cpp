/**
 * @file 15_singleInheritance.cpp
 * @brief Demonstrates single inheritance with public visibility.
 *
 * Notes:
 * - Derived class can access public and protected members of base.
 * - Private members of base are inaccessible directly.
 */

#include <iostream>
#include <string>
using namespace std;

// -------------------- Base Class --------------------
class Base
{
    int data1; // private, cannot be accessed directly in derived

public:
    int data2; // public
    void setData();
    int getData1();
    int getData2();
};

void Base::setData()
{
    data1 = 10;
    data2 = 20;
}
int Base::getData1() { return data1; }
int Base::getData2() { return data2; }

// -------------------- Derived Class --------------------
class Derived : public Base
{
    int data3;

public:
    void process();
    void display();
};

void Derived::process()
{
    // Can access data2 directly, data1 via getter
    data3 = data2 * getData1();
}

void Derived::display()
{
    cout << "value of data1: " << getData1() << endl;
    cout << "value of data2: " << data2 << endl;
    cout << "value of data3: " << data3 << endl;
}

// ------------------------------- Main -------------------------------
int main()
{
    Derived obj;
    obj.setData(); // base class method accessible due to public inheritance
    obj.process(); // compute data3 = data2 * data1
    obj.display(); // print all values

    return 0;
}
