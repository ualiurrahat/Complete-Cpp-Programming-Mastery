/**
 * @file 06_namespaces_implementation.cpp
 * @brief Full definition of `Employee` and a global object inside a namespace.
 *
 * The implementation file contains **definitions** (bodies) of
 * functions declared in the header.  All code stays inside `OurSystem`
 * to keep the global namespace clean.
 *
 * @author Your Name
 * @version 1.0
 * @date 2025‑10‑25
 */

#include "05_namespaces_header_declaration.hpp"

namespace OurSystem
{

    /// Allocate a single global employee instance.
    /// The pointer is declared in the header; this is its definition.
    Employee *emp_glob = new Employee("mostafa");

    /**
     * @brief Employee constructor definition.
     * @param name_ The name to store.
     *
     * Simply copies the parameter into the member variable.
     */
    Employee::Employee(std::string name_) : name(std::move(name_))
    {
        // Intuition: `std::move` avoids an unnecessary copy when the argument
        // is an rvalue (e.g., a temporary string literal).
    }

    /**
     * @brief Prints the employee's name.
     *
     * Uses `std::cout` directly – no `using namespace std;` in headers.
     */
    void Employee::Print() const
    {
        std::cout << "I am " << name << "\n";
    }

} // namespace OurSystem

/**
 * @brief Demonstrates usage of the global employee.
 *
 * The `main` function lives **outside** the namespace but imports
 * the whole `OurSystem` namespace for brevity (acceptable in a tiny demo).
 *
 * @return 0 on success.
 */
#include <iostream>
#include <vector>
using namespace std;       // OK for a small `main` file
using namespace OurSystem; // Bring everything in for demo

int main()
{
    // No qualification needed because of `using namespace OurSystem;`
    emp_glob->Print();

    // Clean‑up (optional but good practice)
    delete emp_glob;
    emp_glob = nullptr;

    return 0;
}