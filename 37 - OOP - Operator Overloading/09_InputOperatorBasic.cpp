/**
 * @file 09_InputOperatorBasic.cpp
 * @brief Demonstrates basic input operator (>>) that modifies object but doesn't chain.
 *
 * Problem: cin >> x returns void → cannot chain: cin >> x >> y
 *
 * Intuition:
 *   - We want to read two integers and store them in MyPair.
 *   - But standard streams expect operator>> to return the stream for chaining.
 */

#include <iostream>
#include <vector>
using namespace std;

class MyPair
{
private:
    int first, second;

public:
    /// Default constructor: initializes to (-1, -1)
    MyPair() : first(-1), second(-1) {}

    /// Parameterized constructor
    MyPair(int first, int second) : first(first), second(second) {}

    void print()
    {
        cout << "(" << first << "," << second << ")\n";
    }

    int GetFirst() const { return first; }
    void SetFirst(int first) { this->first = first; }
    int GetSecond() const { return second; }
    void SetSecond(int second) { this->second = second; }
};

/**
 * @brief Input operator (non-chainable version).
 * @param input The input stream (cin).
 * @param[out] pair The MyPair object to fill.
 *
 * Reads two integers from input and stores them.
 * Limitation: Returns void → cannot chain: cin >> x >> y
 */
void operator>>(istream &input, MyPair &pair)
{
    int a, b;
    cin >> a >> b;
    pair.SetFirst(a);
    pair.SetSecond(b);
}

int main()
{
    MyPair x, y;

    // Works: reads one object
    cin >> x;
    x.print();

    // ERROR: cannot chain
    // cin >> x >> y;  // void return breaks chaining

    return 0;
}