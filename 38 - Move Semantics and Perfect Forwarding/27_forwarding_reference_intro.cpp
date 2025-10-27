// 27_forwarding_references_intro.cpp
#include <iostream>
using namespace std;

/**
 * @brief Introduces **forwarding references** (`T&&` in template context).
 *
 * @details
 * - `T&&` in a **template** is **not** an rvalue reference.
 * - It's a **forwarding reference** — can bind to **lvalue** or **rvalue**.
 * - Compiler deduces `T` and **collapses** reference:
 *   - `f(int&)`  → `T = int&`
 *   - `f(int&&)` → `T = int`
 */
template <typename T>
void f(T &&a)
{
    // a can be lvalue or rvalue reference
}

// Generated functions:
void f_gen(const int &a) {} // from const int
void f_gen(int &a) {}       // from int&
void f_gen(int &&a) {}      // from int&&

int main()
{
    int val = 2;
    const int CCC = 3;

    f(CCC); // T = const int& → f(const int&)
    f(val); // T = int&       → f(int&)
    f(100); // T = int        → f(int&&)

    return 0;
}