/**
 * @file 04_lambda_as_function_objects.cpp
 * @brief Treat lambdas as callable objects (functors) in generic code.
 *
 * A lambda without capture is implicitly convertible to a function pointer.
 * But more powerfully, any lambda can be passed where a callable is expected.
 * We define a generic `foreach` template that accepts:
 * - Function pointers
 * - Functors (function objects)
 * - Lambdas
 */

#include <iostream>
#include <vector>
using namespace std;

// Template function: applies 'operation' to each element in vector
// 'Function' can be any callable: function pointer, functor, lambda
template <typename Function>
void foreach (vector<int> &vec, Function operation)
{
    for (auto &item : vec)
        operation(item); // Call the provided operation
}

// Regular function (can be passed as pointer)
void square(int &x)
{
    x = x * x;
}

// Functor: struct with operator()
struct AddOne
{
    void operator()(auto &x)
    {
        ++x;
    }
};

// Lambda stored in variable (can be reused)
auto print = [](const auto x)
{ cout << x << " "; };

int main()
{
    vector<int> vec{1, 2, 3, 4, 5};

    // 1. Pass functor object
    foreach (vec, AddOne())
        ; // Each element += 1 → {2,3,4,5,6}

    // 2. Pass function pointer
    foreach (vec, square)
        ; // Square each → {4,9,16,25,36}

    // 3. Pass inline lambda
    foreach (vec, [](int &x)
             { --x; })
        ; // Decrement → {3,8,15,24,35}

    // 4. Pass stored lambda
    foreach (vec, print)
        ; // Print: 3 8 15 24 35
    cout << "\n";

    return 0;
}