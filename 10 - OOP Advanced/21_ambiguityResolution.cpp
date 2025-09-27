/*
Problem Statement:

Demonstrate ambiguity resolution in multiple inheritance.

    - Ambiguity arises when two base classes have functions with the same name,
      and the derived class inherits them.
    - The derived class must explicitly specify which base class function to call
      using the scope resolution operator.
    - Also demonstrate function overriding in single inheritance.

@note
Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

/**
 * @brief Base1 class with a greet function.
 */
class Base1
{
public:
    void greet()
    {
        cout << "How are you?" << endl;
    }
};

/**
 * @brief Base2 class with a greet function (same as Base1).
 */
class Base2
{
public:
    void greet()
    {
        cout << "Kemon acho?" << endl;
    }
};

/**
 * @brief Derived class inherits from both Base1 and Base2.
 *        Ambiguity arises for greet().
 */
class Derived : public Base1, public Base2
{
public:
    /// @brief Resolves ambiguity by explicitly calling Base1's greet().
    void greet()
    {
        Base1::greet();
    }
};

/**
 * @brief Class B with say function.
 */
class B
{
public:
    void say()
    {
        cout << "Class B says hello" << endl;
    }
};

/**
 * @brief Class D overrides say function of B.
 */
class D : public B
{
public:
    void say()
    {
        cout << "Class D says hello" << endl;
    }
};

int main()
{
    cout << "----- Ambiguity Demonstration -----" << endl;
    Base1 ob1;
    Base2 ob2;
    ob1.greet();
    ob2.greet();

    Derived ob3;
    ob3.greet(); // Ambiguity resolved inside Derived class.

    cout << "\n----- Overriding Demonstration -----" << endl;
    B b;
    b.say();

    D d;
    d.say(); // Overrides B's say()

    return 0;
}
