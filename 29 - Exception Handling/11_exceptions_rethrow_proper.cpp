/**
 * @file 11_exceptions_rethrow_proper.cpp
 * @brief `throw;` rethrows the **same** exception object.
 *
 * No copy, no slicing. Preserves original exception.
 */

#include <iostream>
#include <stdexcept>

void f3()
{
    throw std::runtime_error("A run time error");
}

void f2()
{
    try
    {
        f3();
    }
    catch (std::runtime_error &e)
    {
        std::cout << "f2 caught at: " << &e << "\n";
        throw; // Same object → no copy
    }
}

void f1()
{
    try
    {
        f2();
    }
    catch (std::runtime_error &e)
    {
        std::cout << "f1 caught at: " << &e << "\n";
        throw; // Same object again
    }
}

int main()
{
    try
    {
        f1();
    }
    catch (std::runtime_error &e)
    {
        std::cout << "main caught at: " << &e << "\n";
    }
    return 0;
}