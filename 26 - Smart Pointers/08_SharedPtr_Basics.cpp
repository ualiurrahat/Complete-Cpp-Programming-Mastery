/**
 * @file 08_SharedPtr_Basics.cpp
 * @brief `std::shared_ptr` — shared ownership with reference counting.
 *
 * Problem Statement:
 * Multiple owners, automatic cleanup when last owner dies.
 *
 * New Topics Introduced:
 * - `use_count()` → number of owners
 * - Copying increases count
 * - `make_shared<T>` → preferred
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <memory>
using namespace std;

int main() {
    auto p1 = make_shared<int>(20);
    cout << p1.use_count() << "\n";  // 1

    {
        auto p2 = p1;  // copy
        auto p3 = p1;
        cout << p1.use_count() << "\n";  // 3
    }  // p2, p3 destroyed → count = 1

    cout << p1.use_count() << "\n";  // 1
    return 0;
}