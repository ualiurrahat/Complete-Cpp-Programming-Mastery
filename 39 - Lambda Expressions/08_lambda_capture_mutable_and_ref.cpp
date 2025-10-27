/**
 * @file 08_lambda_capture_mutable_and_ref.cpp
 * @brief Compares `[=]`, `[=] mutable`, and `[&]` capture lists.
 *
 * - `[=]`: copies, read-only unless `mutable`
 * - `[=] mutable`: copies, but allows modification of copies
 * - `[&]`: references, changes affect originals
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a = 1, b = 5;

    // [=]: capture by value → read-only
    [=]()
    {
        // ++a; // Compilation Error
        cout << a << " " << b << "\n"; // Output: 1 5
    }();

    // [=] mutable: allows modifying the copies
    [=]() mutable
    {
        ++a, ++b;
        cout << a << " " << b << "\n"; // Output: 2 6
    }();

    // [&]: capture by reference → modifies originals
    [&]()
    {
        ++a, ++b;
        cout << a << " " << b << "\n"; // Output: 2 6
    }();

    cout << a << " " << b << "\n"; // Output: 2 6 (modified by [&])

    return 0;
}