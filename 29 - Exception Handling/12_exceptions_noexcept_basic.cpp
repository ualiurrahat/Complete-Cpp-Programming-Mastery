/**
 * @file 12_exceptions_noexcept_basic.cpp
 * @brief `noexcept` marks functions that won't throw.
 *
 * If a `noexcept` function throws, `std::terminate()` is called.
 */

#include <iostream>

int my_abs(int x) noexcept
{
    if (x < 0)
        return -x;
    return x;
}

int my_abs_div(int x, int y) noexcept(true)
{
    return my_abs(x) / my_abs(y); // Assumes y != 0
}

int main()
{
    std::cout << my_abs_div(6, 2) << "\n"; // 3
    std::cout << "Bye\n";
    return 0;
}