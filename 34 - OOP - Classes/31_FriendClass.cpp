/**
 * @file 31_FriendClass.cpp
 * @brief `friend class B` allows B to access **all** private members of A.
 *
 * - Breaks encapsulation **selectively**
 * - Useful for tightly coupled classes (e.g., iterator + container)
 */

#include <iostream>
#include <vector>
using namespace std;

class A
{
private:
    int a1_private = 10;
    int a2_private = 20;

    void HiddenA()
    {
        cout << "I am hidden from outside\n";
    }

public:
    // B can access everything in A
    friend class B;
};

class B
{
public:
    void AccessA1(const A &x)
    {
        cout << "A::a1_private = " << x.a1_private << "\n";
    }

    void AccessA2(A &x)
    {
        cout << "A::a2_private = " << x.a2_private << "\n";
        x.HiddenA(); // Can call private function!
    }
};

int main()
{
    A a;
    B b;

    b.AccessA1(a); // 10
    b.AccessA2(a); // 20 + "I am hidden..."

    return 0;
}