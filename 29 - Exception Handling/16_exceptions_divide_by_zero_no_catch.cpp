/**
 * @file 16_exceptions_divide_by_zero_no_catch.cpp
 * @brief Division by zero → **undefined behavior**, not exception.
 *
 * C++ does **not** throw for `/ 0`. It's UB.
 */

#include <iostream>

int my_abs(int x)
{
    return x < 0 ? -x : x;
}

int my_abs_div(int x, int y)
{
    return my_abs(x) / my_abs(y); // y == 0 → UB!
}

int main()
{
    try
    {
        std::cout << my_abs_div(6, 0) << "\n"; // Undefined Behavior
    }
    catch (...)
    {
        std::cout << "oooh\n"; // Not reached
    }
    std::cout << "Bye\n"; // May or may not print
    return 0;
}