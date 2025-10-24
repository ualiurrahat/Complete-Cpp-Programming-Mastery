/**
 * @file 08_FunctionPointer_StdFunction.cpp
 * @brief `std::function` — type-erased callable wrapper.
 *
 * Problem Statement:
 * Accept lambda with capture using `std::function`.
 *
 * New Topics Introduced:
 * - `std::function<bool(int,int)>`
 * - Can wrap: function, lambda, functor
 * - Has overhead
 *
 * @note Time Complexity: O(n²)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

using Comparator = std::function<bool(int, int)>;

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
    int count = 0;
    auto cmp = [&count](int a, int b) {
        ++count;
        return a > b;
    };
    MySort(v, cmp);
    for (int x : v) cout << x << " ";
    cout << "\nCount: " << count << "\n";  // 15
    return 0;
}