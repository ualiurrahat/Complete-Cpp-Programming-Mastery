/**
 * @file 30_StaticComplexObjects.cpp
 * @brief `static` members can be complex objects: vectors, arrays, classes.
 *
 * - All `static` members must be **defined outside** the class
 * - POD types (like `int arr[10]`) are zero-initialized by default
 * - Non-POD types (`vector`, `B`) need explicit initialization
 */

#include <iostream>
#include <vector>
using namespace std;

class A
{
public:
    A() { cout << "A default ctor\n"; }
};

class B
{
public:
    int f;
    B(int a, int b) : f(10)
    {
        cout << "B parameterized ctor\n";
    }
};

class C
{
public:
    static vector<int> v; ///< Dynamic array
    static int arr[10];   ///< Fixed array (zero-initialized)
    static A a;           ///< Default-constructed
    static B b;           ///< Must be initialized explicitly
};

// Definitions
vector<int> C::v = vector<int>(20, 5); // 20 elements, all 5
int C::arr[10];                        // Zero-initialized: {0,0,...,0}
A C::a;                                // Calls A's default ctor
B C::b = B(1, 2);                      // Explicit init

int main()
{
    cout << "C::v.size() = " << C::v.size() << "\n"; // 20
    cout << "C::v[0] = " << C::v[0] << "\n";         // 5
    cout << "C::arr[5] = " << C::arr[5] << "\n";     // 0
    cout << "C::b.f = " << C::b.f << "\n";           // 10

    return 0;
}