/**
 * @file 14_exceptions_noexcept_conditional.cpp
 * @brief `noexcept(expression)` — conditional exception specification.
 *
 * `noexcept(noexcept(...))` checks if subexpression can throw.
 */

#include <iostream>
#include <vector>

int my_abs(int x)
{
    throw 2;
    return x < 0 ? -x : x;
}

int my_abs_div(int x, int y) noexcept(noexcept(my_abs(y)))
{
    return my_abs(x) / my_abs(y);
}

template <typename T>
T MakeCopy(T const &src) noexcept(noexcept(T(src)))
{
    return src;
}

int main()
{
    std::cout << noexcept(my_abs(0)) << "\n";                    // 0 (false)
    std::cout << noexcept(my_abs_div(0, 0)) << "\n";             // 0
    std::cout << noexcept(MakeCopy(std::vector<int>())) << "\n"; // 0

    try
    {
        my_abs_div(6, 2);
    }
    catch (...)
    {
    }

    std::cout << "Bye\n";
    return 0;
}