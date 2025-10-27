// 24_introduction_to_any.cpp
/**
 * @file 24_introduction_to_any.cpp
 * @brief Basic usage of std::any — type-erased container for any copyable type.
 *
 * `std::any` can hold **any copy-constructible** value.
 * Type information is preserved at runtime via `type()`.
 * Use `any_cast<T>` to retrieve — throws `bad_any_cast` on mismatch.
 *
 * Warning: Less type-safe than `variant`. Use only when type is truly unknown.
 */

#include <iostream>
#include <any>
#include <string>
using namespace std;

int main()
{
    cout << "=== std::any basics ===\n";

    any nothing1;         // Empty
    any nothing2 = any{}; // Also empty

    any a(12.5);          // Holds double
    a = string("Hello!"); // Now holds string
    a = 16;               // Now holds int

    any b = a; // Copy (deep copy of int)

    cout << "Current value: " << any_cast<int>(a) << '\n'; // 16

    // Safe cast with pointer
    string *pstr = any_cast<string>(&a);
    cout << "Cast to string*: " << (pstr ? *pstr : "nullptr") << '\n'; // nullptr

    // Modify via reference
    any_cast<int &>(a) = 11;
    cout << "After ref modify: " << any_cast<int>(a) << '\n'; // 11

    // Reset
    a.reset();
    cout << "Has value? " << (a.has_value() ? "yes" : "no") << '\n'; // no

    return 0;
}