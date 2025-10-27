// 24_swap_based_move.cpp
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/**
 * @brief Move via `swap` — exception-safe and reusable.
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

    MyPair &operator=(MyPair &other)
    {
        cout << "Assignment lvalue\n";
        if (this == &other)
            return *this;
        SetFirst(*other.firstPtr);
        SetSecond(*other.secondPtr);
        return *this;
    }

    MyPair(MyPair &&other) noexcept
    {
        cout << "Delegate to operator=(MyPair&&)\n";
        *this = std::move(other); // Reuse move assignment
    }

    MyPair &operator=(MyPair &&other) noexcept
    {
        cout << "Assignment rvalue\n";
        if (this == &other)
            return *this;
        other.swap(*this); // Swap guts
        return *this;      // old data now in 'other' → freed in dtor
    }

    void swap(MyPair &other) noexcept
    {
        std::swap(firstPtr, other.firstPtr);
        std::swap(secondPtr, other.secondPtr);
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
    MyPair p1 = std::move(MyPair(2, 5));
    p1.print();

    return 0;
}