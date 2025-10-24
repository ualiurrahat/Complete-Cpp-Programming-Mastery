/**
 * @file 18_PointerToObjects.cpp
 * @brief Pointers to non-primitive types: string, vector, etc.
 *
 * Problem Statement:
 * Use pointers to modify complex objects.
 *
 * New Topics Introduced:
 * - Pointer to `string`, `vector`
 * - `*ptr = new_value` replaces entire object
 *
 * @note Time Complexity: O(1) or O(n) depending on assignment
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    string str = "mostafa";
    string *ptr2 = &str;
    *ptr2 = "ali";
    cout << str << "\n";  // ali

    vector<int> v{5, 6, 7};
    vector<int> *ptr3 = &v;
    *ptr3 = vector<int>(10);  // Replace with 10 zeros
    cout << v.size() << "\n";  // 10

    return 0;
}