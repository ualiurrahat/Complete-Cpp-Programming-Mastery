/**
 * @file 09_SharedPtr_Vector.cpp
 * @brief Store `shared_ptr` in containers.
 *
 * Problem Statement:
 * Use `shared_ptr` in `vector` — count increases on copy.
 *
 * New Topics Introduced:
 * - `vector<shared_ptr<T>>`
 * - `push_back()` copies → increases `use_count`
 *
 * @note Time Complexity: O(n)
 * @note Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

int main() {
    auto p = make_shared<int>(10);
    vector<shared_ptr<int>> vec;

    vec.push_back(p);
    vec.push_back(p);
    vec.push_back(p);

    cout << p.use_count() << "\n";  // 4

    vec.clear();
    cout << p.use_count() << "\n";  // 1

    return 0;
}