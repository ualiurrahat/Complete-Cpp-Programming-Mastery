/**
 * @file 26_StaticFunctionLocal.cpp
 * @brief `static` local variable retains value between function calls.
 *
 * - `i1`: regular → reset each call
 * - `i2`: `static` → initialized **once**, persists
 * - Like a global, but **scoped** to the function
 */

#include <iostream>
#include <vector>
using namespace std;

void hello()
{
    int i1 = 0;        // Reinitialized every call
    static int i2 = 0; // Initialized only on first call

    cout << i1 << " " << i2 << "\n";
    i1++;
    i2++;
}

int main()
{
    hello(); // 0 0
    hello(); // 0 1
    hello(); // 0 2

    return 0;
}