/**
 * @file 19_ArrayPointerEquivalence.cpp
 * @brief Arrays decay to pointers; `arr` == `&arr[0]`.
 *
 * Problem Statement:
 * Show that array name is a pointer to first element.
 *
 * New Topics Introduced:
 * - **Array-to-pointer decay**
 * - `arr[i]` ≡ `*(arr + i)`
 * - Pointer can be used like array
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int arr[]{3, 5, 7, 9};
    cout << arr << "\n";  // Address of arr[0]

    int &val = arr[0];
    cout << val << " " << &val << "\n";

    int *ptr = arr;
    ptr[0] = 10, ptr[1] = 20;

    for (auto &v : arr)
        cout << v << " ";
    cout << "\n";  // 10 20 7 9

    return 0;
}