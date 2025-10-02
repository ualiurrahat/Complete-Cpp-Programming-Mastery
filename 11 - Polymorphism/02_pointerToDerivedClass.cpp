/**
 * @file 02_pointerToDerivedClass.cpp
 * @brief Demonstrating base class pointers pointing to derived class objects.
 *
 * - A base class pointer can point to a derived class object.
 * - But a base class pointer cannot access members that are only in the derived class.
 * - When calling a function through a base class pointer, the base class version will run
 *   (unless declared `virtual` in base).
 */

#include <iostream>
using namespace std;

/// Base class
class Base
{
public:
    int base_var;

    void display()
    {
        cout << "Displaying base class variable base_var = " << base_var << endl;
    }
};

/// Derived class
class Derived : public Base
{
public:
    int derived_var;

    void display()
    {
        cout << "Displaying base class variable base_var = " << base_var << endl;
        cout << "Displaying derived class variable derived_var = " << derived_var << endl;
    }
};

/**
 * @brief Main function to demonstrate pointer behavior.
 */
int main()
{
    // Base and Derived objects
    Base base_obj;
    Derived derived_obj;

    // Base class pointer pointing to derived object
    Base *base_pointer = &derived_obj;
    base_pointer->base_var = 25;

    // Calls Base::display() since no virtual keyword
    base_pointer->display();

    // Derived pointer can access both base and derived members
    Derived *derived_pointer = &derived_obj;
    derived_pointer->base_var = 8;
    derived_pointer->derived_var = 40;
    derived_pointer->display();

    return 0;
}
