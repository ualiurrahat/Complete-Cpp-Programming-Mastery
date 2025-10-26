/**
 * @file 33_FriendGlobalFunction.cpp
 * @brief Global function declared as `friend` of a class.
 *
 * - `PrintA` can access **all** private members of `A`
 * - Useful for debugging, serialization, or testing
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
        cout << "I am hidden\n";
    }

public:
    // Global function is friend
    friend void PrintA(A &x);
};

/**
 * @brief Prints all private data of A (for demo).
 * @param x Reference to A object
 */
void PrintA(A &x)
{
    cout << x.a1_private << "\n";
    cout << x.a2_private << "\n";
    x.HiddenA();
}

int main()
{
    A a;
    PrintA(a);

    return 0;
}