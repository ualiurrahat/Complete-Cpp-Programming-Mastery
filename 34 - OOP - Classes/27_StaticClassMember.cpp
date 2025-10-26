/**
 * @file 27_StaticClassMember.cpp
 * @brief `static` member belongs to **class**, not object.
 *
 * - `Test::x` is shared by **all instances**
 * - Must be **defined outside** the class
 * - Accessed via `Test::x` or object (but better via class)
 */

#include <iostream>
#include <vector>
using namespace std;

class Test
{
public:
    static int x; ///< Declaration: shared storage
};

int Test::x = 0; ///< Definition: allocates memory

void f()
{
    Test::x += 10; // Modify shared value
}

int main()
{
    Test::x += 1;            // Direct class access
    f();                     // +10
    cout << Test::x << "\n"; // 11

    Test t1, t2;
    t1.x = 100;           // Also modifies shared x
    cout << t2.x << "\n"; // 100

    return 0;
}