// 19_generic_lambda_visitor.cpp
/**
 * @file 19_generic_lambda_visitor.cpp
 * @brief Uses a generic lambda as a visitor for std::variant.
 *
 * `std::visit` accepts any callable with overloaded `operator()` for each
 * variant type. A **generic lambda** (`auto&& arg`) works for **all types**
 * that support `operator<<`.
 *
 * Ideal for quick debugging or uniform handling.
 */

#include <iostream>
#include <variant>
#include <string>
using namespace std;

int main()
{
    using VarType = variant<int, double, string>;

    VarType var("Mostafa");

    // Generic lambda: works for any type with operator<<
    auto lambda_visitor = [](auto &&arg)
    {
        cout << arg << "\n";
    };

    cout << "Visiting variant: ";
    visit(lambda_visitor, var); // Outputs: Mostafa

    // Try with other types
    var = 42;
    visit(lambda_visitor, var); // 42

    var = 3.14;
    visit(lambda_visitor, var); // 3.14

    return 0;
}