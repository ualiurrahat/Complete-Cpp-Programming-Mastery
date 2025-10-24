/**
 * @file 07_FunctionPointer_Lambda.cpp
 * @brief Lambda to function pointer (no capture).
 *
 * Problem Statement:
 * Use lambda where function pointer expected.
 *
 * New Topics Introduced:
 * - Lambda → function pointer **only if no capture**
 * - Implicit conversion
 *
 * @note Time Complexity: O(n²)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

using Comparator = bool (*)(int, int);

void MySort(vector<int>& v, Comparator cmp) {
    int n = v.size();
    for (int i = 0; i < n - 1; ++i) {
        int max_idx = i;
        for (int j = i + 1; j < n; ++j)
            if (cmp(v[j], v[max_idx])) max_idx = j;
        swap(v[i], v[max_idx]);
    }
}

int main() {
    vector<int> v{1, 8, 2, 9, 3, 0};
    auto cmp = [](int a, int b) { return a > b; };
    MySort(v, cmp);
    for (int x : v) cout << x << " ";
    cout << "\n";
    return 0;
}