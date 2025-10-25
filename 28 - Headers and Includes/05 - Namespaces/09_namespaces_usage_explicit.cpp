/**
 * @file 09_namespaces_usage_explicit.cpp
 * @brief Demonstrates explicit namespace usage (no `using namespace`).
 *
 * Best practice: **avoid `using namespace` in global scope**, especially in headers.
 * Use full qualification (`OurSystem::`) or local `using` declarations.
 *
 * @author Your Name
 * @version 1.0
 * @date 2025-10-25
 */

#include "07_namespaces_header_clean.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "Hello world\n";

    // --- Local object creation (stack-allocated) ---
    // Fully qualified — clear and safe.
    OurSystem::Employee local_employee("Belal");

    // Call method on local object
    local_employee.Print();

    // --- Global object usage ---
    // Access global pointer defined in implementation file
    OurSystem::emp_glob->Print();

    // --- Clean up global allocation (good practice) ---
    delete OurSystem::emp_glob;
    OurSystem::emp_glob = nullptr;

    return 0;
}