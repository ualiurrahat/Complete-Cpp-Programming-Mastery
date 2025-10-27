/**
 * @file 10_InputOperatorChainable.cpp
 * @brief Fixes input operator to return istream& for chaining.
 *
 * Key Insight:
 *   - Standard pattern: operator>> must return the stream
 *   - Enables: cin >> x >> y >> z;
 */

#include <iostream>
#include <vector>
using namespace std;

class MyPair
{
private:
    int first, second;

public:
    MyPair() : first(-1), second(-1) {}
    MyPair(int first, int second) : first(first), second(second) {}

    void print()
    {
        cout << "(" << first << "," << second << ")\n";
    }

    int GetFirst() const { return first; }
    void SetFirst(int first) { this->first = first; }
    int GetSecond() const { return second; }
    void SetSecond(int second) { this->second = second; }

    /// Friend declaration for stream operator
    friend istream &operator>>(istream &input, MyPair &pair);
};

/**
 * @brief Chainable input operator.
 * @param input Input stream.
 * @param pair Object to populate.
 * @return Reference to input stream (for chaining).
 *
 * Flow:
 *   1. Read two ints directly into private members (friend access)
 *   2. Return the stream
 */
istream &operator>>(istream &input, MyPair &pair)
{
    input >> pair.first >> pair.second;
    return input;
}

int main()
{
    MyPair x, y;

    // Now chaining works!
    cin >> x >> y;

    x.print(); // e.g., (1 2)
    y.print(); // e.g., (3 4)

    return 0;
}