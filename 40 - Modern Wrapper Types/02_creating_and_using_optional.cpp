// 02_creating_and_using_optional.cpp
/**
 * @file 02_creating_and_using_optional.cpp
 * @brief Shows various ways to create, inspect, and manipulate std::optional objects.
 *
 * std::optional<T> represents a value of type T that may or may not be present.
 * It is null-state safe and supports value semantics. This file demonstrates:
 * - Construction (direct, make_optional, default)
 * - Checking presence (has_value(), operator bool)
 * - Accessing value (value(), *, ->)
 * - Safe defaults (value_or)
 * - Resetting and reassigning
 */

#include <iostream>
#include <optional>
using namespace std;

int main()
{
    // 1. Direct initialization with value
    optional<int> x1{5}; // Contains 5
    optional x2{5};      // Type deduced as optional<int>

    // 2. Using make_optional (C++17)
    auto x3 = make_optional(5); // Same as optional<int>{5}

    // 3. Empty optionals
    optional<int> x4{nullopt}; // Explicitly no value
    optional<int> x5{};        // Default-constructed → no value

    // --- Checking for value ---
    if (x3.has_value())
        cout << "x3 contains: " << x3.value() << endl; // Safe access

    if (!x4)
        cout << "x4 is empty so far" << endl; // operator bool

    // --- Safe access with default ---
    cout << "x5.value_or(-1) = " << x5.value_or(-1) << endl; // Returns -1

    // --- DANGEROUS: Don't do this on empty optional ---
    // cout << x5.value() << endl;     // Throws bad_optional_access
    // cout << *x5 << endl;            // Undefined behavior

    // --- Resetting and reassigning ---
    x1.reset();   // Now empty
    x2 = nullopt; // Now empty
    x2 = 20;      // Now contains 20

    if (x2)
    {
        cout << "x2 now contains: " << *x2 << endl;
    }

    return 0;
}