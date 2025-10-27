// 09_advanced_optional_iterator_and_modification.cpp
/**
 * @file 09_advanced_optional_iterator_and_modification.cpp
 * @brief Generic find_if returning optional<iterator> with safe modification.
 *
 * Shows how to:
 * - Return optional iterator from generic range
 * - Safely erase found element using iterator from optional
 * - Use structured binding with optional iterator
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>
using namespace std;

/**
 * @brief Generic find_if for any forward range.
 * @tparam Range Any range with begin()/end()
 * @tparam Pred Predicate
 * @return optional<iterator> to first match, or nullopt
 *
 * Uses decltype to deduce iterator type. Works with vector, list, array, etc.
 */
template <class Range, class Pred>
auto find_if(Range &&range, Pred &&p)
{
    auto b = begin(range), e = end(range);
    auto r = std::find_if(b, e, p);
    using iterator = decltype(r);
    if (r == e)
        return optional<iterator>(); // Not found
    return optional<iterator>(r);    // Found
}

bool IsEven(int x)
{
    return x % 2 == 0;
}

int main()
{
    vector<int> v{1, 2, 5};

    // Check existence
    if (find_if(v, IsEven))
        cout << "There is an even number" << endl;

    // Find and erase
    if (auto oit = find_if(v, IsEven))
    {
        v.erase(*oit); // Dereference optional<iterator>
        cout << "After erase, size = " << v.size() << endl;
    }

    return 0;
}