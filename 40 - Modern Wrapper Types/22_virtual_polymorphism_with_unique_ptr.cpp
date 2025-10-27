// 22_virtual_polymorphism_with_unique_ptr.cpp
/**
 * @file 22_virtual_polymorphism_with_unique_ptr.cpp
 * @brief Classic OOP polymorphism using virtual functions and smart pointers.
 *
 * This is the **traditional** way to handle heterogeneous objects:
 * - Base class with virtual functions
 * - Derived classes override
 * - Store via `unique_ptr<Base>`
 *
 * Compare with `std::variant` in later examples — both solve heterogeneity,
 * but in different ways.
 */

#include <iostream>
#include <memory>
using namespace std;

class Base
{
public:
    virtual ~Base() = default;

    /** @brief Virtual function to be overridden */
    virtual void PrintName() const
    {
        cout << "calling Base!\n";
    }
};

class Derived : public Base
{
public:
    void PrintName() const override
    {
        cout << "calling Derived!\n";
    }
};

class ExtraDerived : public Base
{
public:
    void PrintName() const override
    {
        cout << "calling ExtraDerived!\n";
    }
};

int main()
{
    cout << "=== Polymorphism via unique_ptr<Base> ===\n";
    unique_ptr<Base> ptr = make_unique<ExtraDerived>();
    ptr->PrintName(); // Correctly calls ExtraDerived::PrintName

    // Can reassign to different type
    ptr = make_unique<Derived>();
    ptr->PrintName();

    return 0;
}