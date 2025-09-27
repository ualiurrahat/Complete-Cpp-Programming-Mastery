/**
 * @file 19_multipleInheritance.cpp
 * @brief Demonstrates Multiple Inheritance in C++.
 *
 * @details
 * - Multiple inheritance occurs when a class inherits from more than one base class.
 * - Example: Derived class inherits from Base1 and Base2.
 *
 * Syntax:
 * @code
 * class Derived : public Base1, public Base2
 * {
 *     // Derived class members
 * };
 * @endcode
 */

#include <iostream>
#include <string>
using namespace std;

// ---------------------- Base Class 1 ----------------------
class Base1
{
protected:
    int base1int; ///< Example integer from Base1

public:
    void set_base1int(int a) { base1int = a; }
};

// ---------------------- Base Class 2 ----------------------
class Base2
{
protected:
    int base2int; ///< Example integer from Base2

public:
    void set_base2int(int a) { base2int = a; }
};

// ---------------------- Derived Class ----------------------
class Derived : public Base1, public Base2
{
public:
    void show()
    {
        cout << "The value of base1int is " << base1int << endl;
        cout << "The value of base2int is " << base2int << endl;
        cout << "The sum of base1int and base2int is " << base1int + base2int << endl;
    }
};

// ---------------------- Main Function ----------------------
int main()
{
    Derived rahat;

    // Step 1: Assign values from Base1 and Base2.
    rahat.set_base1int(25);
    rahat.set_base2int(8);

    // Step 2: Display results from Derived class.
    rahat.show();

    return 0;
}
