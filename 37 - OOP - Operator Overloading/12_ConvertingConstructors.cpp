/**
 * @file 12_ConvertingConstructors.cpp
 * @brief Implicit conversion from int to MyPair via constructor.
 *
 * Converting constructor: MyPair(int x)
 *   → Allows: MyPair z = 5;
 *   → Calls MyPair(5, 5)
 */

#include <iostream>
#include <vector>
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

    /// Converting constructor: int → MyPair(x,x)
    MyPair(int x) : MyPair(x, x) {}

    /// Regular constructor
    MyPair(int first, int second) : first(first), second(second) {}
};

/**
 * @brief Global operator+ for MyPair.
 */
MyPair operator+(const MyPair &c1, const MyPair &c2)
{
    return MyPair(c1.GetFirst() + c2.GetFirst(),
                  c1.GetSecond() + c2.GetSecond());
}

int main()
{
    MyPair x(1, 2);
    MyPair y(3);  // Converting constructor: MyPair(3,3)
    MyPair w = 5; // Implicit conversion: MyPair(5,5)

    MyPair z1 = x + 5.3;   // 5.3 → int → MyPair(5,5)
    MyPair z2 = 3 + x;     // 3 → MyPair(3,3)
    MyPair z3 = 3 + x + 5; // Multiple conversions

    w.print();  // (5,5)
    z1.print(); // (6,7)
    z2.print(); // (4,5)
    z3.print(); // (9,10)

    return 0;
}