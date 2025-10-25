/**
 * @file 03_exceptions_custom_error_code.cpp
 * @brief Throws primitive int as exception (allowed but not recommended).
 *
 */

#include <iostream>
#include <stdexcept>

int *CreateArrayOnMobile(int len)
{
    /// Step 1: Check for invalid length
    if (len <= 0)
        throw 17; // Custom error code (int)

    /// Step 2: Check memory limit
    if (len >= 10000)
        throw std::runtime_error("Too big array for this mobile memory");

    /// Step 3: Allocate → may throw std::bad_alloc
    return new int[len];
}

int main()
{
    int *p = nullptr; // Will hold array pointer if successful

    /// Wrap risky operation in try block
    try
    {
        /// Try to create array with invalid size (-10)
        p = CreateArrayOnMobile(-10);
        /// If no exception, p now points to array
    }
    /// Catch custom int error code
    catch (int error_code)
    {
        std::cout << "Error code: " << error_code << "\n";
    }
    /// Catch standard runtime error
    catch (const std::runtime_error &e)
    {
        std::cout << "runtime_error: " << e.what() << "\n";
    }
    /// Catch-all for unexpected types (e.g., bad_alloc)
    catch (...)
    {
        std::cout << "Caught unknown exception type!\n";
    }

    /// Only delete if allocation succeeded
    if (p != nullptr)
    {
        delete[] p;
        p = nullptr;
    }

    return 0;
}