/**
 * @file 05_namespaces_header_declaration.hpp
 * @brief Header‑only declaration of a type inside a namespace.
 *
 * Header files should contain **declarations** only.
 * Include guards (`#ifndef … #define … #endif`) prevent multiple inclusion.
 * All entities are placed inside `OurSystem` to avoid global‑namespace pollution.
 *
 * @author Your Name
 * @version 1.0
 * @date 2025‑10‑25
 */

#ifndef OURSYSTEM_EMPLOYEE_HPP
#define OURSYSTEM_EMPLOYEE_HPP

#include <string>
#include <iostream>

/// All project‑specific entities live here.
namespace OurSystem
{

    /**
     * @struct Employee
     * @brief Simple employee representation.
     *
     * Holds a name and provides a print method.
     */
    struct Employee
    {
        std::string name; ///< Employee's full name.

        /**
         * @brief Constructs an Employee.
         * @param name_ Name to assign.
         *
         * The constructor is **declared** here; definition lives in the .cpp file.
         */
        explicit Employee(std::string name_);

        /**
         * @brief Prints the employee's name.
         *
         * Example output: `I am Alice`
         */
        void Print() const;
    };

    /// Global pointer to a dynamically allocated Employee.
    /// Declared `extern` – definition resides in a translation unit.
    extern Employee *emp_glob;

} // namespace OurSystem

#endif // OURSYSTEM_EMPLOYEE_HPP