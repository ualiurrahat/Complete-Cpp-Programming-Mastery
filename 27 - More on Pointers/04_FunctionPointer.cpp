/**
 * @file 04_FunctionPointer.cpp
 * @brief Pointer to function — store function address.
 *
 * Problem Statement:
 * Call functions dynamically via pointers.
 *
 * New Topics Introduced:
 * - `int (*p)(int, int)` → pointer to function
 * - `&func` or `func` both work
 * - Enables callbacks
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

int Add(int x, int y) { return x + y; }
void Print(string s) { cout << s << "\n"; }

int main() {
    int (*pAdd)(int, int) = Add;
    void (*pPrint)(string) = Print;

    cout << pAdd(2, 3) << "\n";  // 5
    pPrint("Hello");

    return 0;
}