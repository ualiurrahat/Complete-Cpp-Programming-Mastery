/**
 * @file 08_namespaces_implementation_clean.cpp
 * @brief Definition of `Employee` members and global instance.
 *
 * All implementations are inside `OurSystem` namespace.
 * Uses modern initialization and move semantics.
 *
 * @author Your Name
 * @version 1.0
 * @date 2025-10-25
 */

#include "07_namespaces_header_clean.hpp"
#include <iostream> // for std::cout

namespace OurSystem
{

    /// Definition of the global employee pointer.
    /// Allocated once at program start.
    Employee *emp_glob = new Employee("mostafa");

    /**
     * @brief Constructor definition.
     * @param name_ Name to store (rvalue optimized via move).
     *
     * Intuition: `std::move` turns the parameter into an rvalue,
     * allowing::string can steal its internal buffer — zero-copy when possible.
     */
    Employee::Employee(std::string name_)
        : name(std::move(name_))
    {
        // Member initializer list is more efficient than assignment.
    }

    /**
     * @brief Prints employee name in a friendly format.
     *
     * Example: "I am mostafa"
     */
    void Employee::Print() const
    {
        std::cout << "I am " << name << '\n';
    }

} // namespace OurSystem