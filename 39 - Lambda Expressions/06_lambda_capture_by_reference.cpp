/**
 * @file 06_lambda_capture_by_reference.cpp
 * @brief Shows selective capture: specific variables by reference or value.
 *
 * You can mix capture modes: `[&var1, var2]` → `var1` by ref, `var2` by value.
 * This gives fine-grained control over lifetime and mutability.
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec{1, 2, 3, 4};
    int factor = 2, sum = 0;

    // Capture 'sum' by reference: changes affect original
    auto sum_oper = [&sum](auto &v)
    {
        for (auto &item : v)
            sum += item;
    };
    sum_oper(vec); // sum = 3+4+5+6 = 18

    // Mixed capture: 'factor' by ref, 'sum' by value
    [&factor, sum]()
    {
        // factor++;     // OK: modifies original
        // sum++;        // OK: modifies copy
    };

    return 0;
}