/**
 * @file 03_namespaces_using_directive.cpp
 * @brief Illustrates the `using namespace` directive.
 *
 * A `using namespace` directive brings **all** names from a namespace
 * into the current scope.  It is convenient for small scopes but can
 * lead to name clashes in larger programs.
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

/// Make **every** identifier from `Customer` visible in this translation unit.
using namespace Customer;

/**
 * @brief Program entry point.
 *
 * All members of `Customer` (`first` and `second`) are directly usable.
 * `Admin::total` is imported locally to avoid a global `using namespace Admin;`.
 *
 * @return 0 on successful termination.
 */
int main()
{
    // No qualification needed for Customer members.
    std::cout << first << "\n";
    std::cout << first << "\n";
    std::cout << second << "\n";
    std::cout << second << "\n";

    // Bring only `total` from Admin into this function.
    using Admin::total;
    // Alternative (also valid): using namespace Admin;
    std::cout << total << "\n";

    return 0;
}