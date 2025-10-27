/**
 * @file 15_lambda_internals_and_conversion.cpp
 * @brief How compilers implement lambdas under the hood.
 *
 * A lambda expression generates:
 * 1. A unique unnamed class type (closure type)
 * 2. An instance of that class (closure object)
 *
 * - Captured variables → data members
 * - `mutable` → removes `const` from `operator()`
 * - No captures → convertible to function pointer
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Example closure type (simulated — real name is unutterable)
struct __lambda_unique_name
{
    // const by default unless lambda is mutable
    void operator()(int i) const
    {
        cout << i;
    }
};

int main()
{
    // Simple lambda: no capture
    [](int i)
    { cout << i; };

    // Compiler does:
    // 1. Generate unique type like __lambda_123
    // 2. Create object and call operator()

    __lambda_unique_name obj;
    obj(10); // Output: 10

    // If lambda captures variables:
    // [x, &y]() { ... } → x and y become members of the closure type

    // Important: Lambdas with no capture can be converted to function pointers
    auto fp = +[](int x)
    { return x * x; }; // Unary + forces conversion
    // fp now has type: int(*)(int)

    return 0;
}