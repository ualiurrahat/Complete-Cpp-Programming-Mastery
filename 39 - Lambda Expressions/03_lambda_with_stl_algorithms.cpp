/**
 * @file 03_lambda_with_stl_algorithms.cpp
 * @brief Practical use of lambdas with STL algorithms like count_if, sort.
 *
 * Lambdas shine when used directly inside algorithm calls.
 * We show:
 * - Named lambda
 * - Inline anonymous lambda
 * - Immediate invocation
 * - Parameterless lambda
 * - Custom comparator in sort
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsOdd1(int n)
{
    return n % 2 != 0;
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5};

    // Named lambda used with count_if
    auto IsOdd2 = [](int n)
    { return n % 2 != 0; };
    cout << count_if(v.begin(), v.end(), IsOdd2) << "\n"; // Output: 3

    // Anonymous lambda passed directly to algorithm
    cout << count_if(v.begin(), v.end(),
                     [](int n)
                     { return n % 2 != 0; })
         << "\n"; // Output: 3

    // Regular function and immediate lambda invocation
    cout << IsOdd1(11) << "\n"; // 1 (true)
    cout << [](int n)
    { return n % 2 != 0; }(11) << "\n"; // 1 (true)

    // Parameterless lambda (prints message)
    []()
    { cout << "anonymous\n"; }(); // Immediate execution

    // Custom sort: descending order using lambda comparator
    sort(begin(v), end(v),
         [](int i, int j)
         { return i > j; }); // Greater-than for descending

    // Print sorted vector (optional verification)
    // for(int x : v) cout << x << " ";  // 5 4 3 2 1

    return 0;
}