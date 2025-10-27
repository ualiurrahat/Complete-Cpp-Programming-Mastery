// 34_variadic_factory_pattern.cpp
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

/**
 * @brief Generic factory using variadic templates + perfect forwarding.
 *
 * @details
 * - `Args&&... args` → forwarding references.
 * - `forward<Args>(args)...` → preserves each argument's value category.
 * - Works for any type with any constructor.
 */
template <typename T, typename... Args>
T create(Args &&...args)
{
    return T(std::forward<Args>(args)...);
}

int main()
{
    int val = create<int>(7);
    double doub = create<double>(); // default ctor

    string s = "mostafa";
    cout << create<string>(s) << " ";          // copy
    cout << create<string>("mostafa") << "\n"; // move

    vector<int> v1 = std::move(create<vector<int>>(5, 1000));
    cout << v1.size() << " " << v1[0] << "\n"; // 5 1000

    using vec1d = vector<int>;
    using vec2d = vector<vec1d>;
    vec2d v2 = std::move(create<vec2d>(7, create<vec1d>(3, 153)));

    return 0;
}