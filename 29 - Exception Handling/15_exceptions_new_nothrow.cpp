/**
 * @file 15_exceptions_new_nothrow.cpp
 * @brief `new (std::nothrow)` — allocation without exception.
 *
 * Returns `nullptr` on failure instead of throwing `std::bad_alloc`.
 */

#include <iostream>
#include <new>

int main()
{
    const int sz = 10;

    // Way 1: Regular new → throws on failure
    try
    {
        int *ptr1 = new int[sz];
        delete[] ptr1;
        ptr1 = nullptr;
    }
    catch (const std::bad_alloc &ex)
    {
        std::cerr << "Failed: " << ex.what() << "\n";
    }

    // Way 2: nothrow new → returns nullptr
    int *ptr2 = new (std::nothrow) int[sz];
    if (!ptr2)
    {
        std::cout << "Failed!\n";
    }
    else
    {
        std::cout << "Succeeded!\n";
        delete[] ptr2;
        ptr2 = nullptr;
    }

    return 0;
}