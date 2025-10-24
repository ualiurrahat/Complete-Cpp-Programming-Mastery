/**
 * @file 09_ReferencesIntro.cpp
 * @brief Introduces C++ references — aliases to existing variables.
 *
 * Problem Statement:
 * Demonstrate how references work as alternative names for variables.
 * Show that multiple references point to the same memory location.
 *
 * New Topics Introduced:
 * - **Reference (`&`)**: Not a pointer. It's an alias to a variable.
 * - **Same memory address**: `&ref == &original`
 * - **Value change propagates**: Modifying reference affects original.
 *
 * Use Case: Pass-by-reference, avoid copying large objects.
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

int main() {
    int age = 55;
    cout << age << " " << &age << "\n";  // 55 0x...

    int &ref1 = age;
    cout << ref1 << " " << &ref1 << "\n";  // 55 same_address

    int &ref2 = ref1;
    cout << ref2 << " " << &ref2 << "\n";  // 55 same_address

    ref1 = 10;
    cout << age << " " << ref1 << " " << ref2 << "\n";  // 10 10 10

    return 0;
}