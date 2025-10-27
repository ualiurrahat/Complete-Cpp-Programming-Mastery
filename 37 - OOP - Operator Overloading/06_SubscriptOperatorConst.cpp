/**
 * @file 06_SubscriptOperatorConst.cpp
 * @brief Overloads '[]' for read-only access (const version).
 *
 * Why const?
 *   - x[0] returns a temporary int
 *   - Cannot modify: x[0] = 5 → error (lvalue required)
 *   - Safe for const objects
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

    int GetFirst() const { return first; }
    void SetFirst(int first) { this->first = first; }
    int GetSecond() const { return second; }
    void SetSecond(int second) { this->second = second; }

    MyPair operator!()
    {
        cout << "Here\n";
        MyPair &c1 = *this;
        return MyPair(-1 * c1.GetFirst(), -1 * c1.GetSecond());
    }

    /**
     * @brief Overloads '[]' for read-only access.
     * @param pos Index (0 = first, 1 = second)
     * @return The value at the given position.
     *
     * Note: Returns by value → temporary → cannot assign
     */
    int operator[](int pos) const
    {
        if (pos == 0)
            return GetFirst();
        return GetSecond();
    }
};

int main()
{
    MyPair x(10, 20);
    cout << x[0] << " " << x[1] << "\n"; // 10 20

    // x[0] = 7;  // ERROR: returns temporary int
    // Reason: x[0] calls operator[] → returns int by value → rvalue

    return 0;
}