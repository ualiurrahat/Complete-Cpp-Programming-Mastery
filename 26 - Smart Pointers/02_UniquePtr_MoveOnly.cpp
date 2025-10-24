/**
 * @file 02_UniquePtr_MoveOnly.cpp
 * @brief `unique_ptr` is move-only — no copying allowed.
 *
 * Problem Statement:
 * Show that `unique_ptr` cannot be copied, only moved.
 *
 * New Topics Introduced:
 * - **Deleted copy constructor**
 * - `std::move()` to transfer ownership
 * - After move: original becomes `nullptr`
 *
 * @warning Never use moved-from `unique_ptr`
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> p1 = make_unique<int>(20);

    // unique_ptr<int> p2 = p1;  // ERROR: copy deleted
    unique_ptr<int> p2 = std::move(p1);  // OK: ownership transferred

    if (p1 == nullptr)
        cout << "p1 is null after move\n";

    cout << *p2 << "\n";  // 20
    p2 = nullptr;         // Explicit cleanup

    return 0;
}