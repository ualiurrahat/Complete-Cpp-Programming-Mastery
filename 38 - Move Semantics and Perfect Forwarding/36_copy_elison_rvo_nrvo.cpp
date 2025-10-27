// 36_copy_elision_rvo_nrvo.cpp
#include <iostream>
#include <utility>
using namespace std;

/**
 * @brief Demonstrates **Copy Elision** (RVO/NRVO) in C++17.
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
    MyPair Get1() { return MyPair(3, 6); } // RVO: mandatory elision
    MyPair Get2()
    {
        MyPair p1(2, 5);
        return p1;
    }                           // NRVO: allowed
    MyPair Get3() { return p; } // Must copy/move
};

int main()
{
    Manager mgr;
    MyPair p1 = mgr.Get2();
    // Only: Constructor → ~MyPair() (temp destroyed)
    // NO copy/move!

    return 0;
}