// 08_rvalue_references_intro.cpp
#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

/**
 * @brief Introduces rvalue references (C++11) and their performance benefit.
 *
 * @details
 * - `int&&` binds to **prvalues** (temporaries) directly — no copy.
 * - Avoids unnecessary copying of large objects.
 * - Temporaries live until the end of the full expression.
 */
int main()
{
    int a = 10;

    // lvalue reference: binds to named object
    int &lvalue_ref = a;

    // prvalue: 2*a + 1 → temporary
    int t = 2 * a + 1;
    // → temp created → value copied into t

    // rvalue reference: binds directly to temporary
    int &&r1 = 2 * a + 1;
    // → temp created → its **address** stored in r1 → NO copy!

    // CE: cannot bind rvalue ref to lvalue
    // int &&r2 = a;

    cout << "r1 (bound to temp): " << r1 << endl;

    return 0;
}