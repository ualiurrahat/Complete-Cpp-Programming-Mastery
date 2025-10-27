/**
 * @file 04_MixedTypeOperators.cpp
 * @brief Overloads operators with mixed types: MyPair + int, int * MyPair, etc.
 *
 * Key Insight:
 *   - Member operators: left must be object → can't do `5 + x`
 *   - Global operators: both sides are parameters → enables symmetry
 *   - For chaining like `a + b + c`, all intermediate results must support next operation
 */

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class MyPair
{
private:
    int first, second;

public:
    MyPair(int first, int second) : first(first), second(second) {}

    MyPair Add(const MyPair &c2)
    {
        MyPair &c1 = *this;
        return MyPair(c1.GetFirst() + c2.GetFirst(), c1.GetSecond() + c2.GetSecond());
    }

    void print()
    {
        cout << "(" << first << "," << second << ")\n";
    }

    int GetFirst() const { return first; }
    void SetFirst(int first) { this->first = first; }
    int GetSecond() const { return second; }
    void SetSecond(int second) { this->second = second; }
};

/* ==================== OPERATOR OVERLOADS ==================== */

// 1. MyPair + MyPair (MUST HAVE for chaining)
MyPair operator+(const MyPair &c1, const MyPair &c2)
{
    return MyPair(c1.GetFirst() + c2.GetFirst(),
                  c1.GetSecond() + c2.GetSecond());
}

// 2. MyPair + int
MyPair operator+(const MyPair &c1, int x)
{
    return MyPair(c1.GetFirst() + x, c1.GetSecond() + x);
}

// 3. int + MyPair
MyPair operator+(int x, const MyPair &c1)
{
    return MyPair(c1.GetFirst() + x, c1.GetSecond() + x);
}

// 4. int * MyPair
MyPair operator*(int x, const MyPair &c1)
{
    return MyPair(c1.GetFirst() * x, c1.GetSecond() * x);
}

// 5. MyPair - std::pair
MyPair operator-(const MyPair &c1, pair<int, int> p)
{
    return MyPair(c1.GetFirst() - p.first, c1.GetSecond() - p.second);
}

/* ========================= MAIN ========================= */
int main()
{
    pair<int, int> p = make_pair(1, 3);
    MyPair x(1, 2);

    MyPair z1 = x + 5; // MyPair + int
    MyPair z2 = 3 * x; // int * MyPair
    MyPair z3 = x - p; // MyPair - pair

    z1.print(); // (6,7)
    z2.print(); // (3,6)
    z3.print(); // (0,-1)

    // NOW WORKS: 3 * x → MyPair
    //           + 5   → MyPair + int
    //           + x   → MyPair + MyPair
    MyPair z4 = 3 * x + 5 + x;
    z4.print(); // (9,13)

    return 0;
}