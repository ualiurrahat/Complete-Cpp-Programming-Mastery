/**
 * @file 02_StructHeader.cpp
 * @brief Header – **declaration** of `struct Employee` and its members.
 *
 * @note Only declarations; definitions live in the .cpp file.
 * @note `using namespace std;` is **not** placed here – avoid namespace pollution.
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>   // needed for std::string
#include <iostream> // needed for std::ostream (if you add << later)

struct Employee
{
    std::string name;

    /** @brief Constructor declaration. */
    Employee(std::string name_);

    /** @brief Print member function declaration. */
    void Print() const;
};

/** @brief Global pointer to a dynamically allocated Employee. */
extern Employee *emp_glob;

#endif /* EMPLOYEE_H_ */