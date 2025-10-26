/**
 * @file 12_MyNumberPassByValueRef.cpp
 * @brief Shows why **pass-by-value** triggers copy, but **reference** does not.
 *
 * - `play1(MyNumber())` → temporary → copy into parameter
 * - `play2(MyNumber())` → error: cannot bind temporary to non-const lvalue ref
 * - `play3(MyNumber())` → OK with `const MyNumber&`
 * - `play4()` returns object → RVO may skip copy
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

    MyNumber(const MyNumber &another)
    {
        cout << "Copy constructor\n";
        val1 = new int;
        *val1 = *another.val1;
        val2 = another.val2;
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

void play1(MyNumber a)
{ // copy
    cout << "play1: copy received\n";
}

void play2(MyNumber &a)
{ // non-const lvalue ref
    // cannot bind temporary
}

void play3(const MyNumber &a)
{ // const lvalue ref → OK with temporary
    cout << "play3: reference to const\n";
}

MyNumber play4()
{
    MyNumber x(1, 1);
    cout << "play4: returning object\n";
    return x; // RVO may eliminate copy
}

int main()
{
    play1(MyNumber()); // copy from temporary
    // play2(MyNumber());          // ERROR
    play3(MyNumber()); // OK
    // play2(play4());             // ERROR: temporary

    cout << "\nNote: Copy constructor may be skipped due to RVO!\n";
    return 0;
}