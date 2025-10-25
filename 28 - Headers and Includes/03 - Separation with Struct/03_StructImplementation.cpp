/**
 * @file 03_StructImplementation.cpp
 * @brief Source file – **definitions** of `Employee` members and global pointer.
 *
 * @note All required headers are included via the header file.
 */

#include "02_StructHeader.cpp"

Employee *emp_glob = new Employee("mostafa");

Employee::Employee(std::string name_) : name(name_) {}

void Employee::Print() const
{
    std::cout << "I am " << name << "\n";
}