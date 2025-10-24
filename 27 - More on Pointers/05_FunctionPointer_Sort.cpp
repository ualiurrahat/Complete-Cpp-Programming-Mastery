/**
 * @file 05_FunctionPointer_Sort.cpp
 * @brief Pass comparator as function pointer.
 *
 * Problem Statement:
 * Custom sort using function pointer.
 *
 * New Topics Introduced:
 * - Function pointer as parameter
 * - Decouple algorithm from comparison
 *
 * @note Time Complexity: O(n²)
 * @note Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

bool cmp(int a, int b) { return a > b; }

void MySort(vector<int>& v, bool (*CMP)(int, int)) {
    int n = v.size();
    for (int i = 0; i < n - 1; ++i) {
        int max_idx = i;
        for (int j = i + 1; j < n; ++j)
            if (CMP(v[j], v[max_idx])) max_idx = j;
        swap(v[i], v[max_idx]);
    }
}

int main() {
    vector<int> v{1, 8, 2, 9, 3, 0};
    MySort(v, cmp);
    for (int x : v) cout << x << " ";  // 9 8 3 2 1 0
    cout << "\n";
    return 0;
}