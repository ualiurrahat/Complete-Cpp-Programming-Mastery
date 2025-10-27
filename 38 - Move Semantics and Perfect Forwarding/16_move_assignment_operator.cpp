// 16_move_assignment_operator.cpp
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/**
 * @brief Implements move assignment to transfer ownership.
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

        // Free current
        if (firstPtr)
            delete firstPtr;
        if (secondPtr)
            delete secondPtr;

        // Steal
        firstPtr = other.firstPtr;
        secondPtr = other.secondPtr;
        other.firstPtr = other.secondPtr = nullptr;
        return *this;
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
    MyPair p1;
    p1 = MyPair(1, 5); // Move assignment
    // Constructor → Move Assignment → ~temp (empty)

    MyPair p2;
    p2 = p1; // Copy assignment

    p1.print();
    p2.print();

    return 0;
}