/**
 * @file 04_namespaces_nested_and_alias.cpp
 * @brief Demonstrates nested namespaces and namespace aliases.
 *
 * Namespaces can be nested to model hierarchical domains.
 * C++17 introduced the concise `namespace A::B {}` syntax.
 * A **namespace alias** (`namespace short = long::path::to;`) shortens
 * repetitive qualification.
 *
 * @author Your Name
 * @version 1.0
 * @date 2025‑10‑25
 */

#include <iostream>

/// Hierarchical system model.
namespace OurSystem
{
    /// Customer‑specific limits.
    namespace Customer
    {
        /// Maximum number of items a customer may hold.
        int limit = 1;
    }

    /// Administrator‑specific limits.
    namespace Admin
    {
        /// Higher limit for administrative users.
        int limit = 10;
    }
} // namespace OurSystem

/**
 * @brief Program entry point.
 *
 * Prints the nested limits using both full qualification and a
 * namespace alias for brevity.
 *
 * @return 0 on successful termination.
 */
int main()
{
    // Full qualification – explicit but verbose.
    std::cout << OurSystem::Customer::limit << '\n';

    // Alias makes the code cleaner and easier to refactor.
    namespace cust = OurSystem::Customer; // alias definition
    std::cout << cust::limit << '\n';

    return 0;
}