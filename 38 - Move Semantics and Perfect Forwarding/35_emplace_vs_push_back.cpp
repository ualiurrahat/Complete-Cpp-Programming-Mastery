// 35_emplace_vs_push_back.cpp
#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

/**
 * @brief `emplace` uses perfect forwarding to construct in-place.
 *
 * @details
 * - `push_back(make_pair(...))` → creates pair → copies/moves.
 * - `emplace(...args)` → forwards args → constructs **in container**.
 */
int main()
{
    vector<pair<int, string>> v;

    v.push_back(make_pair(2, "mostafa")); // temp pair → move
    v.emplace(v.end(), 3, "ziad");        // direct construction

    for (auto &p : v)
        cout << p.first << ": " << p.second << "\n";

    return 0;
}