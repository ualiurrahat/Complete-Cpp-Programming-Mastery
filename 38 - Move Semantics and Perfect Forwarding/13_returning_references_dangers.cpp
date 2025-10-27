// 13_returning_references_dangers.cpp
#include <iostream>
#include <cmath>
using namespace std;

int global = 20;

/**
 * @brief Shows safe and unsafe ways to return references.
 */
int prvalue()
{
    return 10; // Returns copy → prvalue
}

int &lvalue1()
{
    return global; // OK: global has static storage
}

int &lvalue2()
{
    int local = 20;
    return local; // DANGER: returns reference to destroyed local
}

int &&xvalue()
{
    return 10; // DANGER: returns ref to destroyed temp
}

int main()
{
    int x1 = prvalue(); // OK
    // int &x2 = prvalue();    // CE

    int &&x3 = prvalue(); // OK: binds to temp

    int y1 = lvalue1();
    int &y2 = lvalue1(); // OK
    // int&& y3 = lvalue1();   // CE

    cout << x3 << "\n";
    cout << "bye\n";

    return 0;
}