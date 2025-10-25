/**
 * @file 09_exceptions_partial_construction_leak.cpp
 * @brief Exception in constructor causes memory leak.
 *
 * If `throw` in constructor, **destructor is NOT called**.
 * Any `new` before `throw` is leaked unless RAII used.
 */

#include <iostream>
#include <string>

struct Name
{
    std::string first;
    Name() = default;
    Name(std::string first_) : first(std::move(first_)) {}
    ~Name() { std::cout << "Name Destructor " << first << "\n"; }
};

struct Employee
{
    Name *full_name1 = nullptr;
    Name full_name2;

    Employee()
    {
        full_name1 = new Name("Mostafa"); // Heap allocation
        throw 0;                          // Exception → destructor NOT called!
        full_name2.first = "Belal";       // Never reached
    }

    ~Employee()
    {
        delete full_name1; // Never executed
        std::cout << "Destroy Employee\n";
    }
};

int main()
{
    try
    {
        Employee(); // Object fully constructed? No → exception
    }
    catch (...)
    {
        // Catches everything, but memory is already leaked
    }
    return 0;
}