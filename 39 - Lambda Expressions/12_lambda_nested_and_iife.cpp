/**
 * @file 12_lambda_nested_and_iife.cpp
 * @brief Demonstrates nested lambdas and Immediately Invoked Function Expressions (IIFE).
 *
 * Lambdas can be defined inside other lambdas and invoked immediately.
 * This is useful for scoping, encapsulation, or one-off operations.
 * Forgetting to pass arguments in nested calls causes compilation errors.
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4};

    // IIFE: Lambda defined and called immediately
    // Outer lambda takes vector by reference
    [](auto &vec)
    {
        // Inner lambda: prints a single value
        auto print = [](auto v)
        { cout << v << "\n"; };

        for (auto item : vec)
            print(item); // 1 2 3 4 (each on new line)
    }(v); // Pass 'v' here

    // Alternative: inline nested lambda (no named inner lambda)
    [](auto &vec)
    {
        for (auto item : vec)
            [](auto v)
            { cout << v << "\n"; }(item); // Immediate call
    }(v);

    // Common Error:
    // [](auto &vec) {
    //     for (auto item : vec)
    //         [](auto v) { cout << v << "\n"; };  // Missing (item) → CE
    // }(v);

    return 0;
}