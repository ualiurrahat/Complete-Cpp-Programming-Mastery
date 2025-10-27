/**
 * @file 05_lambda_capture_by_value.cpp
 * @brief Demonstrates capturing variables by value in lambdas.
 *
 * When a variable is captured by value `[var]`, a copy is made at lambda creation.
 * Modifications inside the lambda do not affect the original.
 * Use `mutable` to allow internal modification of the copied value.
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec{1, 2, 3, 4};
    int factor = 2, sum = 0;

    // Capture 'factor' by value: a copy is stored in the lambda
    auto add_user_val1 = [factor](auto &v)
    {
        for (auto &item : v)
            item += factor;
        // factor++; // Compilation Error: 'factor' is const by default
    };
    add_user_val1(vec); // vec becomes {3,4,5,6}

    // With 'mutable': allows modification of the copied 'factor'
    auto add_user_val2 = [factor](auto &v) mutable
    {
        for (auto &item : v)
            item += factor;
        factor = 1000; // Only modifies the copy inside lambda
    };
    add_user_val2(vec);
    cout << factor << "\n"; // Output: 2 (original unchanged)

    return 0;
}