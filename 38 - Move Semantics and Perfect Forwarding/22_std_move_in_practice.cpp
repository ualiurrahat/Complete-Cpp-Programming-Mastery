// 22_std_move_in_practice.cpp
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/**
 * @brief Full class with move semantics + `std::move` usage.
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
    MyPair p1(2, 5);

    MyPair &&pr = std::move(p1); // pr is rvalue ref, but lvalue by name
    v.push_back(pr);             // copy: pr is lvalue
    v.push_back(std::move(p1));  // move: p1 treated as xvalue

    v.back().print();
    // p1.print();  // Runtime error: null pointers

    p1.SetFirst(10); // Safe: SetFirst allocates if null
    p1.SetSecond(20);
    p1.print();

    return 0;
}