/**
 * @file 16_TemplateInitializerList.cpp
 * @brief Template functions cannot deduce `initializer_list` automatically.
 *
 * Must explicitly specify template argument:
 *   `templated_fn<initializer_list<int>>({1,2,3})`
 */

#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

template <typename T>
void templated_fn(T lst)
{
    for (auto item : lst)
        cout << item << " ";
    cout << "\n";
}

int main()
{
    // templated_fn({1, 2, 3});  // ERROR: cannot deduce T

    templated_fn<initializer_list<int>>({1, 2, 3}); // OK
    templated_fn<vector<int>>({1, 2, 3});           // OK: vector ctor from list

    return 0;
}