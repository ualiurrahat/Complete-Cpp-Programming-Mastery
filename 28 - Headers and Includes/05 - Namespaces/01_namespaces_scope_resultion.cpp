/**
 * @file 01_namespaces_scope_resolution.cpp
 * @brief Demonstrates basic namespace usage and scope‑resolution operator (::).
 *
 * Namespaces prevent name collisions by grouping related identifiers.
 * The scope‑resolution operator `::` is used to access members of a namespace.
 *
 * @author Your Name
 * @version 1.0
 * @date 2025‑10‑25
 */

#include <iostream>

/// @brief Global counter – visible everywhere in the translation unit.
int total_users = 0;

namespace OurSystem
{
    /// @brief Counter local to the OurSystem namespace.
    ///        Hides the global `total_users`.
    int total_users = 10;

    /// @brief A constant size used only inside OurSystem.
    const int SIZE = 10;
} // namespace OurSystem

namespace DownloadedSystem
{
    /// @brief Counter from a third‑party library.
    int total_users = 20;
}

/**
 * @brief Program entry point.
 *
 * Prints the values of `total_users` from different scopes and the
 * constant `SIZE` defined inside `OurSystem`.
 *
 * @return 0 on successful termination.
 */
int main()
{
    // Access namespace members explicitly with ::
    std::cout << OurSystem::total_users << '\n';
    std::cout << DownloadedSystem::total_users << '\n';
    std::cout << OurSystem::SIZE << '\n';

    return 0;
}