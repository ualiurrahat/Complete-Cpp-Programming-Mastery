/**
 * @file 13_lambda_init_capture_cpp14.cpp
 * @brief C++14 generalized lambda capture (init-capture).
 *
 * Allows initializing capture variables with arbitrary expressions:
 *   [name = expr, ...]
 *
 * Key uses:
 * - Move semantics (`std::move`)
 * - Computed values
 * - Avoid copying non-copyable types (like `std::ofstream`)
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
using namespace std;

int main()
{
    // Unique pointer to vector of size 20
    auto p = make_unique<vector<int>>(20);
    *p = {1, 2, 3, 4};
    int t = 1;

    // C++14 init-capture: x, y, ptr initialized at capture time
    auto print = [x = 10, y = 2 * t, ptr = move(p)]()
    {
        (void)x;
        (void)y; // Unused, just showing syntax
        for (auto &v : *ptr)
        {
            cout << v << " ";
        }
    };

    print(); // Output: 1 2 3 4
    // p is now nullptr (moved from)

    ofstream ofs("hello.txt");

    // Error: ofstream is not copyable
    // [ofs]() mutable {};  // Compilation Error

    // OK: capture by reference (but risky if lambda outlives stream)
    [&ofs]() mutable {};

    // Best: move ownership into lambda
    [out = move(ofs)]() mutable
    {
        out << "Hello world\n";
    };
    // ofs is now invalid; file is closed when lambda dies

    return 0;
}