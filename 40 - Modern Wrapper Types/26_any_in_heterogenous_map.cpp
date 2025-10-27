// 26_any_in_heterogeneous_map.cpp
/**
 * @file 26_any_in_heterogeneous_map.cpp
 * @brief Stores mixed types in a map using std::any.
 *
 * Common pattern: configuration maps, JSON-like structures.
 * Use `typeid(T)` to dispatch behavior at runtime.
 *
 * Drawback: Runtime type checks, potential `bad_any_cast`.
 */

#include <iostream>
#include <any>
#include <map>
#include <string>
using namespace std;

int main()
{
    cout << "=== Heterogeneous map with std::any ===\n";

    map<string, any> mp;
    mp["integer"] = 10;
    mp["string"] = string("Hello World"); // Explicit string
    mp["float"] = 1.0;

    for (const auto &[key, val] : mp)
    {
        cout << key << ": ";

        if (val.type() == typeid(int))
            cout << "int: " << any_cast<int>(val) << "\n";
        else if (val.type() == typeid(string))
            cout << "string: " << any_cast<string>(val) << "\n";
        else if (val.type() == typeid(double))
            cout << "double: " << any_cast<double>(val) << "\n";
        else
            cout << "unknown type\n";
    }

    return 0;
}