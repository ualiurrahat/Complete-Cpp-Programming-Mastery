/**
 * @file 01_InlineStruct.cpp
 * @brief Struct with **inline member functions** – everything in one file.
 *
 * @note Both definition and implementation are visible to the compiler in the same translation unit.
 */

#include <iostream>
using namespace std;

struct Employee
{
    string name;

    /** @brief Constructor – inline definition. */
    Employee(string name_) : name(name_) {}

    /** @brief Prints the employee's name – inline definition. */
    void Print() const
    {
        cout << "I am " << name << "\n";
    }
};

int main()
{
    Employee e("Mostafa");
    e.Print(); // I am Mostafa
    return 0;
}