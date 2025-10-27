/**
 * @file 02_GlobalOperatorPlus.cpp
 * @brief Overloads '+' as a global (non-member) function.
 *
 * Why global?
 *   - Both operands are passed as parameters.
 *   - Enables symmetric operations and better encapsulation.
 *   - Required for operations like `5 + x` (left is not object).
 */

#include <iostream>
#include <vector>
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

    // Getters needed for global operator+
    int GetFirst() const { return first; }
    void SetFirst(int first) { this->first = first; }
    int GetSecond() const { return second; }
    void SetSecond(int second) { this->second = second; }
};

/**
 * @brief Global operator+ for MyPair addition.
 * @param c1 Left operand.
 * @param c2 Right operand.
 * @return New MyPair with summed values.
 *
 * Intuition:
 *   - No '*this' — both objects are parameters.
 *   - Must use public getters (or make it friend).
 */
MyPair operator+(const MyPair &c1, const MyPair &c2)
{
    return MyPair(c1.GetFirst() + c2.GetFirst(),
                  c1.GetSecond() + c2.GetSecond());
}

int main()
{
    MyPair x(1, 2);
    MyPair y(10, 20);

    MyPair z = x + y; // Calls global operator+
    z.print();        // (11,22)

    return 0;
}