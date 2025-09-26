/**
 * @file 16_singleInheritancePrivate.cpp
 * @brief Demonstrates single inheritance with private visibility.
 *
 * Notes:
 * - Public members of base become private in derived.
 * - Cannot access base members directly from outside the derived class.
 */

#include <iostream>
#include <string>
using namespace std;

// -------------------- Base Class --------------------
class Base
{
    int data1; // private, inaccessible in derived

public:
    int data2;
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
class Derived : private Base
{ // private inheritance
    int data3;

public:
    void process();
    void display();
};

void Derived::process()
{
    setData(); // can still call base method internally
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
    // obj.setData(); // ERROR: base public members are now private in derived
    obj.process(); // internal call works
    obj.display(); // prints all values

    return 0;
}
