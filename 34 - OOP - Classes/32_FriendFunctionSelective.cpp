/**
 * @file 32_FriendFunctionSelective.cpp
 * @brief `friend` a **single function** from another class.
 *
 * - Only `B::AccessA1` can access `A`'s private parts
 * - `B::AccessA2` cannot → **granular control**
 * - Requires forward declaration of `A`
 */

#include <iostream>
#include <vector>
using namespace std;

// Forward declaration
class A;

class B
{
public:
    void AccessA1(A &x);
    void AccessA2(A &x); // Not friend → cannot access private
};

class A
{
private:
    int a1_private = 10;
    int a2_private = 20;

    void HiddenA()
    {
        cout << "I am hidden\n";
    }

public:
    // Only this specific function is friend
    friend void B::AccessA1(A &x);
};

// Implementation
void B::AccessA1(A &x)
{
    cout << x.a1_private << "\n"; // OK
    x.HiddenA();                  // OK
}

void B::AccessA2(A &x)
{
    // cout << x.a2_private << "\n";  // ERROR: private
    // x.HiddenA();                   // ERROR
}

int main()
{
    A a;
    B b;

    b.AccessA1(a); // OK
    // b.AccessA2(a);  // Would fail if uncommented

    return 0;
}