// 07_optional_containers_and_efficiency.cpp
/**
 * @file 07_optional_containers_and_efficiency.cpp
 * @brief Demonstrates std::optional holding containers and efficient operations.
 *
 * optional<vector<T>> is space-efficient and supports:
 * - Copying (deep copy of vector if present)
 * - In-place construction (in_place, emplace)
 * - Relational operators
 * - value_or for safe defaults
 */

#include <iostream>
#include <vector>
#include <optional>
using namespace std;

int main()
{
    // Initialize with a vector
    optional<vector<int>> v{vector<int>{1, 2, 3, 4}};
    optional<vector<int>> cpy = v; // Deep copy

    v = nullopt; // Now empty
    cout << "v is empty, size via value_or: "
         << v.value_or(vector<int>{}).size() << endl; // 0

    cout << "cpy still has size: " << cpy->size() << endl; // 4

    if (v != cpy)
        cout << "v and cpy are different (as expected)" << endl;

    // Efficient in-place construction
    optional<vector<int>> v2(in_place, {1, 2, 3}); // Direct init
    v2 = {3, 4, 5};                                // Assignment
    v2.emplace({3, 4, 5});                         // Reconstruct in-place

    cout << "v2 final size: " << v2->size() << endl;

    return 0;
}