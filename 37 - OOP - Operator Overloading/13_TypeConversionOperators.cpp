/**
 * @file 13_TypeConversionOperators.cpp
 * @brief User-defined conversion operators.
 *
 * Allows:
 *   - MyPair → int
 *   - MyPair → pair<int,int>
 *   - pair<int,int> → MyPair (via constructor)
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
    void print()
    {
        cout << "(" << first << "," << second << ")\n";
    }

    int GetFirst() const { return first; }
    void SetFirst(int first) { this->first = first; }
    int GetSecond() const { return second; }
    void SetSecond(int second) { this->second = second; }

    MyPair(int x) : MyPair(x, x) {}
    MyPair(int first, int second) : first(first), second(second) {}

    /// Converting constructor: pair → MyPair
    MyPair(pair<int, int> p) : first(p.first), second(p.second) {}

    /// Conversion to int: product of components
    operator int()
    {
        return first * second;
    }

    /// Conversion to pair<int,int>
    operator pair<int, int>()
    {
        return make_pair(first, second);
    }
};

int main()
{
    MyPair x(2, 3);

    int r = x;            // operator int() → 6
    pair<int, int> p = x; // operator pair<>() → (2,3)
    x = p;                // MyPair(pair) constructor

    cout << p.first << " " << r << "\n"; // 2 6

    return 0;
}