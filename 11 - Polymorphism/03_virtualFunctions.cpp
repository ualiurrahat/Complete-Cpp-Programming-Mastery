/**
 * @file 03_virtualFunctions.cpp
 * @brief Demonstrating virtual functions in C++.
 *
 * A member function in the base class declared using `virtual`
 * is called a virtual function. It allows run-time polymorphism.
 *
 * Without `virtual`, a base class pointer pointing to a derived object
 * still calls the base class version of the function.
 */

#include <iostream>
using namespace std;

/// Base class
class Base
{
public:
    int base_var = 1;

    /// Virtual function
    virtual void display()
    {
        cout << "Base class display: base_var = " << base_var << endl;
    }
};

/// Derived class
class Derived : public Base
{
public:
    int derived_var = 2;

    void display()
    {
        cout << "Derived class display: base_var = " << base_var << endl;
        cout << "Derived class display: derived_var = " << derived_var << endl;
    }
};

/**
 * @brief Main function demonstrating polymorphism with virtual functions.
 */
int main()
{
    Base base_obj;
    Derived derived_obj;

    // Base pointer to derived object
    Base *base_pointer = &derived_obj;

    // Calls Derived::display() because display() is virtual
    base_pointer->display();

    return 0;
}
