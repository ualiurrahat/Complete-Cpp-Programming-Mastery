// 23_variant_with_non_polymorphic_types.cpp
/**
 * @file 23_variant_with_non_polymorphic_types.cpp
 * @brief Uses std::variant with unrelated types that share a common interface.
 *
 * Unlike virtual inheritance, `variant` doesn't require a base class.
 * You can store **any types** as long as you define how to handle them
 * via a **visitor**.
 *
 * This example shows two unrelated classes with same-named `print()` method.
 * `std::visit` + generic lambda calls the correct one.
 */

#include <iostream>
#include <variant>
using namespace std;

class Base
{
public:
    void print() const
    {
        cout << "calling Base!\n";
    }
};

class ExtraDerived
{
public:
    void print() const
    {
        cout << "calling ExtraDerived!\n";
    }
};

int main()
{
    cout << "=== variant with non-polymorphic but duck-typed objects ===\n";

    variant<Base, ExtraDerived> var(ExtraDerived{});

    // Generic lambda: works if type has .print()
    auto caller = [](const auto &obj)
    {
        obj.print();
    };

    visit(caller, var); // Output: calling ExtraDerived!

    // Switch type
    var = Base{};
    visit(caller, var); // Output: calling Base!

    return 0;
}