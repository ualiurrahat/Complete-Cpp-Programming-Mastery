/**
 * @file 14_UniformInitialization.cpp
 * @brief Shows **priority order** of initialization in C++11.
 *
 * Initialization resolution order:
 * 1. `initializer_list` constructor
 * 2. Regular constructor
 * 3. Aggregate initialization
 *
 * Uniform braces `{}` work everywhere.
 */

#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

struct A
{
    int x, y;
    // Aggregate: no user-declared ctors
};

struct B
{
    int x, y;
    B(int x, int y) : x{x}, y{y} {}
    // Regular ctor
};

struct C
{
    int x, y;
    C(int x, int y) : x{x}, y{y} {}
    C(const initializer_list<int> &v)
    {
        x = *v.begin();
        y = *(v.begin() + 1);
        cout << "initializer_list ctor\n";
    }
};

int main()
{
    A a{1, 3};  // aggregate initialization
    B b{2, 9};  // regular constructor
    C c1{3, 7}; // initializer_list constructor
    C c2(3, 7); // regular constructor (parens)

    cout << "A: " << a.x << "," << a.y << "\n";
    cout << "B: " << b.x << "," << b.y << "\n";
    cout << "C1: " << c1.x << "," << c1.y << "\n";
    cout << "C2: " << c2.x << "," << c2.y << "\n";

    return 0;
}