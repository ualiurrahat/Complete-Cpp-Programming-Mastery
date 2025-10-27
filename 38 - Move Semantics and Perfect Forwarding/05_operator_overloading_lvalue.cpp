// 05_operator_overloading_lvalue.cpp
#include <iostream>
using namespace std;

/**
 * @brief Shows how operator overloading can make expressions lvalues.
 */
class MyPair
{
private:
    int first, second;

public:
    MyPair(int f, int s) : first(f), second(s) {}

    void print() const
    {
        cout << "(" << first << ", " << second << ")\n";
    }

    // Pre-increment: returns *this → lvalue
    MyPair &operator++()
    {
        ++first, ++second;
        return *this;
    }

    // Post-increment: returns copy → prvalue
    MyPair operator++(int)
    {
        MyPair cpy = *this;
        ++first, ++second;
        return cpy;
    }
};

/**
 * @brief Demonstrates lvalue vs prvalue behavior in operator overloading.
 */
int main()
{
    int a = 1;
    int c = 2 * a + 5; // prvalue
    c = a++;           // a++ is prvalue
    ++a = 10;          // ++a is lvalue → assignable
    // a++ = 10;        // CE: a++ is prvalue

    MyPair p(1, 2);

    // ++p returns lvalue → can be assigned
    ++p = MyPair(3, 10);
    (++p).print(); // (4, 11)

    // p++ returns prvalue → assignment has no effect
    p++ = MyPair(200, 300); // temporary discarded
    p++.print();            // (5, 12)

    return 0;
}