// 20_heterogeneous_container_with_variant.cpp
/**
 * @file 20_heterogeneous_container_with_variant.cpp
 * @brief Stores different types in a single vector using std::variant.
 *
 * `vector<variant<T1, T2, ...>>` is a **type-safe heterogeneous container**.
 * Unlike `vector<any>` or `vector<void*>`, it:
 * - Preserves type information
 * - No manual casting
 * - Works with `std::visit`
 *
 * Perfect for config data, ASTs, or mixed-type collections.
 */

#include <iostream>
#include <variant>
#include <vector>
using namespace std;

int main()
{
    using VarType = variant<int, double, string>;

    vector<VarType> vec;

    // Emplace different types directly
    vec.emplace_back(1);
    vec.emplace_back(2.2);
    vec.emplace_back("hello");

    cout << "Contents of heterogeneous vector:\n";
    auto print_visitor = [](auto &&arg)
    {
        cout << "  → " << arg << "\n";
    };

    for (const auto &item : vec)
    {
        visit(print_visitor, item);
    }

    return 0;
}