// 15_introduction_to_variant.cpp
/**
 * @file 15_introduction_to_variant.cpp
 * @brief Basic usage of std::variant — type-safe union.
 *
 * std::variant<T1, T2, ...> can hold **one** value of any listed type.
 * Unlike union, it's type-safe and supports complex types.
 *
 * Key operations:
 * - get<T>(), get<index>()
 * - index()
 * - get_if<T>(&var) → pointer or nullptr
 */

#include <iostream>
#include <variant>
#include <string>
using namespace std;

int main()
{
    variant<string, int> var(10); // Holds int at index 1

    cout << "Value (by index): " << get<1>(var) << endl;  // 10
    cout << "Value (by type): " << get<int>(var) << endl; // 10
    cout << "Active index: " << var.index() << endl;      // 1

    // Safe access with get_if
    auto ptr1 = get_if<int>(&var);
    cout << "get_if<int>: " << (ptr1 ? to_string(*ptr1) : "null") << endl;

    auto ptr2 = get_if<string>(&var);
    cout << "get_if<string>: " << (ptr2 ? "non-null" : "nullptr") << endl;

    // Modify in-place
    get<int>(var) = 20;
    cout << "After assignment: " << get<int>(var) << endl;

    // Switch type
    var = "ali";
    cout << "Now holds string, index: " << var.index() << endl;

    return 0;
}