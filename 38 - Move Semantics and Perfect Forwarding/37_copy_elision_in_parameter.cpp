// 37_copy_elision_in_parameters.cpp
#include <iostream>
#include <utility> // Required for std::move
#include <vector>
using namespace std;

/**
 * @brief Copy elision applies even in function parameters.
 */
class MyPair
{
private:
    int *firstPtr = nullptr;
    int *secondPtr = nullptr;

public:
    MyPair(int first = 0, int second = 0)
    {
        cout << "Constructor\n";
        SetFirst(first), SetSecond(second);
    }

    MyPair(const MyPair &other)
    {
        cout << "Copy Constructor\n";
        SetFirst(*other.firstPtr);
        SetSecond(*other.secondPtr);
    }

    MyPair(MyPair &&other) noexcept
    {
        cout << "Move Constructor\n";
        firstPtr = other.firstPtr;
        secondPtr = other.secondPtr;
        other.firstPtr = other.secondPtr = nullptr;
    }

    MyPair &operator=(MyPair &other)
    {
        cout << "Assignment lvalue\n";
        if (this == &other)
            return *this;
        SetFirst(*other.firstPtr);
        SetSecond(*other.secondPtr);
        return *this;
    }

    MyPair &operator=(MyPair &&other) noexcept
    {
        cout << "Assignment rvalue\n";
        if (this == &other)
            return *this;
        if (firstPtr)
            delete firstPtr;
        if (secondPtr)
            delete secondPtr;
        firstPtr = other.firstPtr;
        secondPtr = other.secondPtr;
        other.firstPtr = other.secondPtr = nullptr;
        return *this;
    }

    ~MyPair()
    {
        cout << "~MyPair()\n";
        if (firstPtr)
            delete firstPtr;
        if (secondPtr)
            delete secondPtr;
    }

    void SetFirst(int v)
    {
        if (!firstPtr)
            firstPtr = new int;
        *firstPtr = v;
    }
    void SetSecond(int v)
    {
        if (!secondPtr)
            secondPtr = new int;
        *secondPtr = v;
    }
    void print() const { cout << "(" << *firstPtr << "," << *secondPtr << ")\n"; }
};

class Manager
{
private:
    MyPair p = MyPair(10, 20);

public:
    void Recieve1(const MyPair &pp)
    {
        p = MyPair(pp); // Copy constructor + assignment
    }

    void Recieve2(MyPair pp)
    {
        p = std::move(pp); // Move assignment (pp is lvalue → std::move makes it xvalue)
    }
};

int main()
{
    Manager mgr;
    const MyPair p_const(2, 7);

    // Case 1: Copy from const lvalue → must copy
    mgr.Recieve2(p_const); // Copy Constructor → Move Assignment

    // Case 2: Pass prvalue → copy elision into parameter pp
    mgr.Recieve1(MyPair(2, 7)); // Direct construction in pp → Copy Assignment

    // Case 3: Pass prvalue → elision + move
    mgr.Recieve2(MyPair(2, 7)); // Direct construct in pp → Move Assignment

    return 0;
}