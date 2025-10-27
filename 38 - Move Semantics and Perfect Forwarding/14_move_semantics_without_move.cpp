// 14_move_semantics_without_move.cpp
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/**
 * @brief Shows copy behavior before move semantics (pre-C++11).
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
    void print() { cout << "(" << *firstPtr << "," << *secondPtr << ")\n"; }
    int GetFirst() const { return *firstPtr; }
    int GetSecond() const { return *secondPtr; }
};

int main()
{
    vector<MyPair> v;

    v.push_back(MyPair(3, 6));
    // 1. Constructor: temp object
    // 2. Copy Constructor: deep copy into vector
    // 3. ~temp: delete original
    // 4. ~copy: delete in vector

    return 0;
}