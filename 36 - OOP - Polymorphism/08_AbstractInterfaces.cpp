// <DOCUMENT filename="08_AbstractInterfaces.cpp">
#include <iostream>
#include <vector>
using namespace std;

/**
 * @file 08_AbstractInterfaces.cpp
 * @brief Pure abstract base w/ multiple inheritance.
 *
 * Design:
 * - `Printable`: pure virtual `Print()`
 * - `Cloneable`: not pure (optional)
 * - `Person` inherits both → must implement `Print()`
 */

class Printable
{
public:
    virtual void Print() const = 0;
    virtual ~Printable() = default;
};

class Cloneable
{
public:
    virtual ~Cloneable() = default;
    // Clone not required
};

class Person : public Printable, public Cloneable
{
public:
    void Print() const override { cout << "Person\n"; }
};

class Employee : public Person
{
};

int main()
{
    Employee e;
    e.Print(); // Works via Printable
    return 0;
}