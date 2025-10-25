/**
 * @file 04_exceptions_proper_hierarchy.cpp
 * @brief Catch blocks in correct order: specific → general.
 *
 */

#include <iostream>
#include <stdexcept>

int *CreateArrayOnMobile(int len)
{
    if (len <= 0)
        throw std::invalid_argument("Array length must be positive!");

    if (len >= 10000)
        throw std::runtime_error("Too big array for mobile memory");

    return new int[len];
}

int main()
{
    int *p = nullptr;

    try
    {
        /// This call throws invalid_argument
        p = CreateArrayOnMobile(-10);
    }
    /// Most specific first
    catch (const std::invalid_argument &e)
    {
        std::cout << "invalid_argument: " << e.what() << "\n";
    }
    /// Then runtime_error
    catch (const std::runtime_error &e)
    {
        std::cout << "runtime_error: " << e.what() << "\n";
    }
    /// Catch-all last
    catch (...)
    {
        std::cout << "Caught unknown exception (e.g., bad_alloc)\n";
    }

    if (p)
    {
        delete[] p;
        p = nullptr;
    }

    return 0;
}