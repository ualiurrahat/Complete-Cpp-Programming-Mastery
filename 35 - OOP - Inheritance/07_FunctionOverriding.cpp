// <DOCUMENT filename="07_FunctionOverriding.cpp">
#include <iostream>
#include <string>
using namespace std;

/**
 * @file 07_FunctionOverriding.cpp
 * @brief Demonstrates function overriding and hiding in inheritance.
 *
 * Key Concepts:
 * - Same function name + signature in derived class → overrides base
 * - Base version is HIDDEN unless called explicitly
 * - Works with both pointers and objects
 */

class A
{
public:
    /** @brief Returns 10 */
    int GetValue()
    {
        return 10;
    }

    /** @brief Returns greeting string */
    string GetStr()
    {
        return "Hello";
    }
};

class B : public A
{
public:
    /** @brief Overrides A's GetValue() */
    int GetValue()
    {
        return 20;
    }

    // Note: GetStr() is inherited unchanged
};

int main()
{
    B b1;
    cout << b1.GetValue() << " " << b1.GetStr() << "\n"; // 20 Hello

    B *b2 = new B();
    cout << b2->GetValue() << " " << b2->GetStr() << "\n"; // 20 Hello
    delete b2;

    // To call base version explicitly:
    // cout << b1.A::GetValue();  // → 10

    return 0;
}