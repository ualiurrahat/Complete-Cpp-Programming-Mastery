// 18_variant_ambiguous_construction.cpp
/**
 * @file 18_variant_ambiguous_construction.cpp
 * @brief Demonstrates ambiguous variant construction and how to resolve it.
 *
 * When multiple variant alternatives can be constructed from a value,
 * the compiler cannot choose — results in **compilation error**.
 *
 * Solutions:
 * - Use `in_place_type<T>` to specify exact type
 * - Use `in_place_index<N>` to specify by position
 * - Avoid overlapping convertible types
 */

#include <iostream>
#include <variant>
#include <vector>
using namespace std;

int main()
{
    cout << "=== Safe construction ===" << endl;
    variant<int, double> var1{10.5}; // OK: 10.5 → double (best match)
    cout << "var1 holds double: " << get<double>(var1) << endl;

    // --- Ambiguous case ---
    // variant<int, float> var2{10.5};  // CE: 10.5 can convert to int OR float

    cout << "\n=== Resolving ambiguity with in_place ===" << endl;

    // Specify type explicitly
    variant<int, float> var2{in_place_type<float>, 10.5f};
    cout << "var2 (float): " << get<float>(var2) << endl;

    // Specify index explicitly
    variant<int, float> var3{in_place_index<0>, 10}; // int at index 0
    cout << "var3 (int): " << get<int>(var3) << endl;

    // --- Efficient in-place construction for containers ---
    cout << "\n=== in_place with initializer_list ===" << endl;
    variant<vector<int>, string> var4{in_place_index<0>, {0, 1, 2, 3}};
    cout << "var4 vector size: " << get<vector<int>>(var4).size() << endl;

    // --- Integer literal disambiguation ---
    variant<float, int, double> var5 = 0; // OK: 0 → int (index 1)
    // variant<float, long, double> var6 = 0; // CE: 0 could be int or long

    variant<float, long, double> var6 = 0L; // OK: 0L → long
    cout << "var6 holds long: " << get<long>(var6) << endl;

    return 0;
}