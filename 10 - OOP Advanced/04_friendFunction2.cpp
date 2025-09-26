/**
 * @file 04_friendFunction2.cpp
 * @brief Demonstrates friend functions with multiple classes in C++.
 *
 * @details
 * A single friend function can be declared in multiple classes,
 * allowing it to access private data from all of them.
 */

#include <iostream>
#include <string>
using namespace std;

// Forward declaration
class Y;

/**
 * @class X
 * @brief Class with private data accessible via friend function.
 */
class X
{
    int data;

public:
    void setValue(int value)
    {
        data = value;
    }

    friend void add(X, Y);
};

/**
 * @class Y
 * @brief Class with private data accessible via friend function.
 */
class Y
{
    int num;

public:
    void setValue(int value)
    {
        num = value;
    }

    friend void add(X, Y);
};

/**
 * @brief Friend function that accesses private data of both X and Y.
 * @param ob1 Object of class X
 * @param ob2 Object of class Y
 */
void add(X ob1, Y ob2)
{
    cout << "Summing the data of X and Y class objects gives me "
         << ob1.data + ob2.num << endl;
}

int main()
{
    X ob1;
    Y ob2;

    ob1.setValue(5);
    ob2.setValue(25);

    add(ob1, ob2);

    return 0;
}
