/**
 * @file 03_UniquePtr_Get.cpp
 * @brief Access raw pointer safely with `.get()`.
 *
 * Problem Statement:
 * Show memory layout: `unique_ptr` object → raw pointer → data.
 *
 * New Topics Introduced:
 * - `p.get()` → returns raw pointer (no ownership transfer)
 * - `&p` → address of `unique_ptr` object
 * - `&raw_p` → address of stored raw pointer
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int> p = make_unique<int>(20);
    int* raw = p.get();

    cout << *raw << " " << raw << " " << &raw << " " << &p << "\n";
    // 20 0x... 0x... 0x...

    return 0;
}