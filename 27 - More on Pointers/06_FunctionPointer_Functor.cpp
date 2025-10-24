/**
 * @file 06_FunctionPointer_Functor.cpp
 * @brief Replace function pointer with functor.
 *
 * Problem Statement:
 * Use class with `operator()` instead of function pointer.
 *
 * New Topics Introduced:
 * - **Functor** = function object
 * - Can have state (unlike function pointer)
 *
 * @note Time Complexity: O(n²)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

struct Comparator {
    bool operator()(int a, int b) { return a > b; }
};

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
    vector<int> v{1, 8, 2, 9, 3, [0]};
    MySort(v, Comparator());
    for (int x : v) cout << x << " ";
    cout << "\n";
    return 0;
}