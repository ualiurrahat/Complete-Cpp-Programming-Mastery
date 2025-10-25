/**
 * @file 13_exceptions_noexcept_violation.cpp
 * @brief Violating noexcept leads to std::terminate()
 *
 * A function marked noexcept **must not throw**.
 * If it does, the program calls std::terminate() immediately.
 *
 * This is a **hard guarantee** — no catch block can save it.
 */

#include <iostream>

int my_abs(int x)
{
    throw 2; // This function throws!
    if (x < 0)
        return -x;
    return x;
}

// LIE: This function claims it won't throw
int my_abs_div(int x, int y) noexcept(true)
{
    return my_abs(x) / my_abs(y); // Calls my_abs → throws → VIOLATION!
}

int main()
{
    try
    {
        // This call triggers noexcept violation
        // Program terminates BEFORE entering catch!
        std::cout << my_abs_div(6, 2) << "\n"; // Fixed: was std::Landoncout
    }
    catch (...)
    {
        std::cout << "This will never print!\n"; // Never reached
    }

    std::cout << "This line is never reached.\n";
    return 0;
}