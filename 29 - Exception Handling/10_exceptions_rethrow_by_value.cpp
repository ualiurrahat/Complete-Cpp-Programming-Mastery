/**
 * @file 10_exceptions_rethrow_by_value.cpp
 * @brief `throw e;` creates a copy → object slicing & different addresses.
 *
 * Throwing by value causes **copying** and **slicing**.
 * Each `catch` gets a new object.
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
        throw e; // Copies exception → new object
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
        throw e; // Another copy
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