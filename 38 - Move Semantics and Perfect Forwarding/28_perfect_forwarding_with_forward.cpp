// 28_perfect_forwarding_with_forward.cpp
#include <iostream>
#include <utility>
using namespace std;

/**
 * @brief Uses `std::forward<T>(a)` to preserve value category.
 */
void g(const int &x) { cout << "g(const int&)\n"; }
void g(int &x)
{
    cout << "g(int&)\n";
    x = 10;
}
void g(int &&x)
{
    cout << "g(int&&)\n";
    x = 20;
}

template <typename T>
void f(T &&a)
{
    g(std::forward<T>(a)); // Preserves original value category
}

int main()
{
    int val = 2;
    int &valr = val;
    const int CC = 3;
    int &&r1 = 10;
    int &r2 = r1;

    // Lvalue cases
    f(CC);   // T = const int& → g(const int&)
    f(val);  // T = int&       → g(int&)
    f(valr); // T = int&       → g(int&)
    f(r1);   // T = int&       → g(int&)  (r1 is lvalue)
    f(r2);   // T = int&       → g(int&)

    cout << val << " " << valr << " " << r1 << "\n"; // 10 10 10

    // Rvalue cases
    f(17);             // T = int → g(int&&)
    f(std::move(r1));  // T = int → g(int&&)
    f(std::move(val)); // T = int → g(int&&)

    cout << val << " " << valr << " " << r1 << "\n"; // 20 20 20

    return 0;
}