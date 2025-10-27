// 30_forward_preserves_const.cpp
#include <iostream>
#include <utility>
using namespace std;

/**
 * @brief `std::forward` preserves `const`-ness.
 */
void g(int &x)
{
    cout << "g(int&)\n";
    x = 10;
}

template <typename T>
void f(T &&a)
{
    g(std::forward<T>(a)); // CE if T is const
}

int main()
{
    f(17); // T = int → OK: g(int&&)
    // f(const int{5});  // T = const int& → CE: cannot bind to non-const

    return 0;
}