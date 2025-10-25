/**
 * @file 02_namespaces_using_declaration.cpp
 * @brief Shows the `using` declaration to bring a single name into the current scope.
 *
 * A `using` declaration imports **one** identifier from a namespace,
 * making repetitive use more concise while keeping the rest of the
 * namespace hidden.
 *
 * @author Your Name
 * @version 1.0
 * @date 2025‑10‑25
 */

#include <iostream>

namespace Customer
{
    /// @brief First customer identifier.
    int first = 1;
    /// @brief Second customer identifier.
    int second = 2;
} // namespace Customer

namespace Admin
{
    /// @brief Total number of admin accounts.
    int total = 5;
} // namespace Admin

/// Bring only `first` into the global scope of this file.
using Customer::first;

/**
 * @brief Program entry point.
 *
 * Demonstrates that `first` can be used without qualification,
 * while `second` remains hidden unless explicitly qualified.
 *
 * @return 0 on successful termination.
 */
int main()
{
    // `first` is now directly accessible – no `Customer::` needed.
    std::cout << first << "\n";
    std::cout << first << "\n";

    // `second` is **not** imported → uncommenting would cause a compilation error.
    // std::cout << second << "\n";

    // Import `total` only for the current block (function scope).
    using Admin::total;
    std::cout << total << "\n";

    return 0;
}