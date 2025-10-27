/**
 * @file 07_lambda_capture_all_by_value.cpp
 * @brief Uses `[=]` to capture all used variables by value.
 *
 * `[=]` copies all variables used inside the lambda.
 * Safe from dangling references, but copies can be expensive for large objects.
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec{1, 2, 3, 4};
    int factor = 2;

    // [=] captures 'factor' and 'vec' by value
    auto add_user_val = [=](auto &v)
    {
        for (auto &item : v)
            item += factor;
    };

    add_user_val(vec); // vec becomes {3,4,5,6}
    // factor remains 2

    int sum = 0;
    // [&] captures all by reference
    auto sum_oper = [&]()
    {
        for (auto &item : vec)
            sum += item;
    };

    sum_oper();
    cout << sum << "\n"; // Output: 18

    return 0;
}