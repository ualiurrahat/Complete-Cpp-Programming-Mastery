// 29_forward_vs_move.cpp
#include <iostream>
#include <utility>
using namespace std;

/**
 * @brief `std::forward` vs `std::move`: conditional vs unconditional.
 */
void g(int x)
{
    cout << "g(int)\n";
    x = 10;
}

template <typename T>
void f(T &&a)
{
    g(std::forward<T>(a)); // Only moves if original was rvalue
}

int main()
{
    int val = 2;

    f(val); // T = int&  → forward → g(int&) → val unchanged
    f(17);  // T = int   → forward → g(int&&) → move

    cout << val << "\n"; // 2

    return 0;
}