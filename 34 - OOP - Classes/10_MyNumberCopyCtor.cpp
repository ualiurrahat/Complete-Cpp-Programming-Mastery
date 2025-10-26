/**
 * @file 10_MyNumberCopyCtor.cpp
 * @brief Introduces **copy constructor** for deep copying.
 *
 * - When copying `b(a)`, we allocate **new memory** for `val1`
 * - Prevents double deletion and memory corruption
 * - Essential when class manages raw resources (Rule of Three/Five)
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
        cout << "Normal constructor\n";
        val1 = new int;
        *val1 = x;
        val2 = y;
    }

    /** @brief Copy constructor – performs deep copy. */
    MyNumber(const MyNumber &another)
    {
        cout << "Copy constructor\n";
        val1 = new int;        // New memory
        *val1 = *another.val1; // Copy value
        val2 = another.val2;
    }

    ~MyNumber()
    {
        delete val1;
        cout << "Destructor called\n";
    }

    void PrintValueAndAddress() const
    {
        cout << "val1: " << *val1 << " @ " << val1 << "\n";
        cout << "val2: " << val2 << " @ " << &val2 << "\n\n";
    }
};

int main()
{
    MyNumber a;    // normal ctor
    MyNumber b(a); // copy ctor → safe deep copy

    a.PrintValueAndAddress();
    b.PrintValueAndAddress();

    return 0;
}