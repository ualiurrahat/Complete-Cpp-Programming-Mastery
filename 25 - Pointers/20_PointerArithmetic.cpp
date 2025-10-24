/**
 * @file 20_PointerArithmetic.cpp
 * @brief Pointer arithmetic: `ptr + n` moves n elements.
 *
 * Problem Statement:
 * Show how `ptr + i` gives address of `arr[i]`.
 *
 * New Topics Introduced:
 * - **Pointer arithmetic scales by type size**
 * - `*(ptr + i)` ≡ `ptr[i]` ≡ `arr[i]`
 * - `ptr - arr` → index
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int arr[]{3, 5, 7, 9};
    int *ptr = arr;

    cout << (ptr + 2) << " " << &arr[2] << "\n";
    cout << *(ptr + 2) << " " << arr[2] << "\n";
    cout << *(ptr + 3) << " " << *ptr + 3 << "\n";  // 9 6

    return 0;
}