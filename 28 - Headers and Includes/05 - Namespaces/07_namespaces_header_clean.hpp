/**
 * @file 07_namespaces_header_clean.hpp
 * @brief Clean header declaring `Employee` inside `OurSystem` namespace.
 *
 * This header follows best practices:
 * - Include guards with unique macro.
 * - Only necessary headers (`<string>`).
 * - No `using namespace std;` — prevents namespace pollution.
 * - All declarations inside `OurSystem`.
 *
 * @author Your Name
 * @version 1.0
 * @date 2025-10-25
 */

#ifndef OURSYSTEM_EMPLOYEE_CLEAN_HPP
#define OURSYSTEM_EMPLOYEE_CLEAN_HPP

#include <string> // for std::string

namespace OurSystem
{

    /**
     * @struct Employee
     * @brief Represents an employee with a name.
     *
     * Provides a constructor and a print method.
     * Designed for use within the `OurSystem` namespace.
     */
    struct Employee
    {
        std::string name; ///< Employee's full name.

        /**
         * @brief Constructs an Employee with given name.
         * @param name_ The name to assign (passed by value, moved internally).
         *
         * Uses move semantics to avoid unnecessary copying.
         */
        explicit Employee(std::string name_);

        /**
         * @brief Prints the employee's greeting.
         * @note Marked `const` — does not modify the object.
         */
        void Print() const;
    };

    /// Global pointer to a dynamically allocated Employee.
    /// Defined in the implementation file.
    extern Employee *emp_glob;

} // namespace OurSystem

#endif // OURSYSTEM_EMPLOYEE_CLEAN_HPP