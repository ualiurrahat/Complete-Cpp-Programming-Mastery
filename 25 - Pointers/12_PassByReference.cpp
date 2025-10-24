/**
 * @file 12_PassByReference.cpp
 * @brief Pass-by-reference vs pass-by-value.
 *
 * Problem Statement:
 * Show how pass-by-reference modifies original variables.
 *
 * New Topics Introduced:
 * - **Pass-by-value**: Copy is made → original unchanged.
 * - **Pass-by-reference**: No copy → original modified.
 *
 * @note Time Complexity: O(1)
 * @note Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

void read(string name, int &x, string &str) {
    cout << "Hello " << name << "\n";
    cin >> x >> str;
    name = "###";  // Only local copy changed
}

int main() {
    string my_name = "mostafa";
    int x;
    string msg;
    read(my_name, x, msg);
    cout << my_name << " " << x << " " << msg << "\n";
    return 0;
}