// 17_variant_with_visitor_pattern.cpp
/**
 * @file 17_variant_with_visitor_pattern.cpp
 * @brief Uses std::visit with a visitor struct for type-safe handling.
 *
 * Instead of manual index() checks, define a visitor with overloaded `operator()`
 * for each variant type. `std::visit` dispatches automatically.
 *
 * Clean, extensible, and compile-time safe.
 */

#include <iostream>
#include <variant>
#include <cmath>
#include <utility>
using namespace std;

using var_roots = variant<pair<double, double>, double, monostate>;

/**
 * @brief Computes quadratic roots and returns via variant.
 */
var_roots compute_roots(double a, double b, double c)
{
    double d = b * b - 4 * a * c;
    if (d > 0.0)
    {
        double p = sqrt(d) / (2 * a);
        return make_pair(-b + p, -b - p);
    }
    else if (d == 0.0)
    {
        return -b / (2 * a);
    }
    else
    {
        return monostate{};
    }
}

/**
 * @brief Visitor to print variant contents.
 */
struct MyVisitor
{
    void operator()(double &root)
    {
        cout << "1 root found: " << root << '\n';
    }
    void operator()(pair<double, double> &roots)
    {
        cout << "2 roots found: " << roots.first << " " << roots.second << '\n';
    }
    void operator()(monostate &)
    {
        cout << "No real roots found.\n";
    }
};

int main()
{
    MyVisitor printer;

    auto res = compute_roots(1, 0, -1);
    std::visit(printer, res);

    res = compute_roots(1, 6, 9);
    visit(printer, res);

    res = compute_roots(1, -3, 4);
    visit(printer, res);

    return 0;
}