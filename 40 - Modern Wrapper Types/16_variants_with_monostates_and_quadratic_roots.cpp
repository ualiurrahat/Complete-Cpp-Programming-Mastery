// 16_variant_with_monostate_and_quadratic_roots.cpp
/**
 * @file 16_variant_with_monostate_and_quadratic_roots.cpp
 * @brief Uses variant to return multiple possible outcomes from quadratic solver.
 *
 * Solve ax² + bx + c = 0 → possible results:
 * - 2 real roots → pair<double,double>
 * - 1 real root → double
 * - No real roots → monostate
 *
 * variant unifies return type. monostate represents "no value".
 */

#include <iostream>
#include <variant>
#include <cmath>
#include <utility>
using namespace std;

using var_roots = variant<monostate, double, pair<double, double>>;

/**
 * @brief Computes roots of quadratic equation ax² + bx + c = 0.
 * @return variant containing 0, 1, or 2 roots
 */
var_roots compute_roots(double a, double b, double c)
{
    double d = b * b - 4 * a * c; // Discriminant
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
        return monostate{}; // No real roots
    }
}

void print(const var_roots &res)
{
    if (res.index() == 0)
        cout << "No real roots found.\n";
    else if (res.index() == 1)
        cout << "1 root found: " << get<1>(res) << '\n';
    else
    {
        auto &[r1, r2] = get<2>(res);
        cout << "2 roots found: " << r1 << " " << r2 << '\n';
    }
}

int main()
{
    print(compute_roots(1, 0, -1)); // 2 roots: 1, -1
    print(compute_roots(1, 6, 9));  // 1 root: -3
    print(compute_roots(1, -3, 4)); // No real roots

    return 0;
}