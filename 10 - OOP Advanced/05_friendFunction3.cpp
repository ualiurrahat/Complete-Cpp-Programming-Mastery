/**
 * @file 05_friendFunction3.cpp
 * @brief Demonstrates friend functions used to swap values between classes.
 *
 * @details
 * This example shows how a friend function can access and manipulate
 * private members of two different classes simultaneously.
 */

#include <iostream>
#include <string>
using namespace std;

// Forward declaration
class C2;

/**
 * @class C1
 * @brief First class with private data.
 */
class C1
{
    int x;

    /// Declare exchange as friend
    friend void exchange(C1 &, C2 &);

public:
    void data(int a)
    {
        x = a;
    }

    void display()
    {
        cout << x << endl;
    }
};

/**
 * @class C2
 * @brief Second class with private data.
 */
class C2
{
    int y;

    /// Declare exchange as friend
    friend void exchange(C1 &, C2 &);

public:
    void data(int b)
    {
        y = b;
    }

    void display()
    {
        cout << y << endl;
    }
};

/**
 * @brief Swaps private data members of two classes using a friend function.
 * @param o1 Object of class C1
 * @param o2 Object of class C2
 */
void exchange(C1 &o1, C2 &o2)
{
    int temp = o1.x;
    o1.x = o2.y;
    o2.y = temp;
}

int main()
{
    C1 ob1;
    C2 ob2;

    ob1.data(25);
    ob2.data(8);

    // Exchange values between two objects
    exchange(ob1, ob2);

    cout << "The values of ob1 after exchanging becomes: ";
    ob1.display();

    cout << "The values of ob2 after exchanging becomes: ";
    ob2.display();

    return 0;
}
