// 08_generic_find_if_returning_optional.cpp
/**
 * @file 08_generic_find_if_returning_optional.cpp
 * @brief Implements a generic find_if that returns optional<iterator>.
 *
 * Standard find_if returns end() on failure. This wrapper returns:
 * - optional with iterator if found
 * - nullopt if not found
 *
 * Safer and more expressive than checking against end().
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>
using namespace std;

/**
 * @brief Finds first element matching predicate, returns optional iterator.
 * @tparam Pred Predicate type
 * @param range Container to search
 * @param p Predicate function
 * @return optional<iterator>: valid iterator or nullopt
 */
template <class Pred>
optional<vector<int>::iterator> find_if(vector<int> &range, Pred p)
{
    auto r = std::find_if(range.begin(), range.end(), p);
    if (r == range.end())
        return {}; // Not found
    return r;      // Found
}

bool IsEven(int x)
{
    return x % 2 == 0;
}

int main()
{
    vector<int> v{1, 2, 5};

    if (find_if(v, IsEven))
        cout << "There is an even number" << endl;
    else
        cout << "No even number found" << endl;

    return 0;
}