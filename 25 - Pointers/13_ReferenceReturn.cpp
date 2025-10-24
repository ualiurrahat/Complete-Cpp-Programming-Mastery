/**
 * @file 13_ReferenceReturn.cpp
 * @brief Returning references from functions and method chaining.
 *
 * Problem Statement:
 * Use reference return to modify object data and enable chaining.
 *
 * New Topics Introduced:
 * - **Reference return**: Allows `obj.func() = value`
 * - **Method chaining**: `obj.setA().setB()`
 * - **Dangling reference risk** if returning local
 *
 * @warning Never return reference to local variable!
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

struct SpecialName {
    string name = "mostafa";
    string& get_name() { return name; }
    void print() { cout << name << "\n"; }
};

int main() {
    SpecialName obj;
    obj.print();  // mostafa

    string &str = obj.get_name();
    str = "ziad";
    obj.print();  // ziad

    obj.get_name() = "belal";
    obj.print();  // belal

    return 0;
}