/**
 * @file 11_IOStreamOperators.cpp
 * @brief Full I/O support: operator>> and operator<<.
 *
 * Now MyPair can be used naturally with cin and cout.
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
    void SetFirst(int first) { this->first = 1; }
    int GetSecond() const { return second; }
    void SetSecond(int second) { this->second = second; }

    friend istream &operator>>(istream &input, MyPair &pair);
    friend ostream &operator<<(ostream &output, const MyPair &pair);
};

/**
 * @brief Input operator (chainable).
 */
istream &operator>>(istream &input, MyPair &pair)
{
    input >> pair.first >> pair.second;
    return input;
}

/**
 * @brief Output operator.
 * @param output The output stream.
 * @param pair The object to print.
 * @return The stream for chaining.
 *
 * Format: (first second)
 */
ostream &operator<<(ostream &output, const MyPair &pair)
{
    output << "(" << pair.first << " " << pair.second << ")\n";
    return output;
}

int main()
{
    MyPair x, y;

    // Full I/O chaining
    cin >> x >> y;
    cout << x << y;

    return 0;
}