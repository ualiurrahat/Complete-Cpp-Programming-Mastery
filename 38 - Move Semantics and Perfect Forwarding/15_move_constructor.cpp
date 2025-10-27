// 15_move_constructor.cpp
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/**
 * @brief Implements move constructor to steal resources.
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
        other.firstPtr = other.secondPtr = nullptr; // Leave in valid state
    }

    ~MyPair()
    {
        cout << "~MyPair()\n";
        if (!firstPtr && !secondPtr)
            cout << "\tFreed already by a move!\n";
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
    void print() { cout << "(" << *firstPtr << "," << *secondPtr << ")\n"; }
};

int main()
{
    vector<MyPair> v;
    v.push_back(MyPair(3, 6));
    // 1. Constructor (temp)
    // 2. Move Constructor → steals pointers
    // 3. ~temp → already empty
    // 4. ~vector element → deletes actual data

    MyPair p1(1, 5);
    MyPair p2(p1); // Copy

    return 0;
}