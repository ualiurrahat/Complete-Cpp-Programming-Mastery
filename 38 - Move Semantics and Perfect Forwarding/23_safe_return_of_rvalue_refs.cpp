// 23_safe_return_of_rvalue_refs.cpp
#include <iostream>
#include <utility>
#include <string>
using namespace std;

string global = "hello";

/**
 * @brief Safe: return rvalue ref to static/global object.
 */
string &&Get()
{
    return std::move(global); // OK: global lives beyond function
}

/**
 * @brief Safe: return moved parameter (still alive).
 */
string &&min_str1(string &&a, string &&b)
{
    if (a < b)
        return std::move(a);
    return std::move(b); // OK: a/b are parameters → destroyed after return
}

/**
 * @brief DANGER: return moved local → dangling.
 */
string &&min_str2(string a, string b)
{
    if (a < b)
        return std::move(a);
    return std::move(b); // WRONG: a/b are locals → destroyed
}

int main()
{
    string &&s = min_str1(string("Mostafa"), string("Ziad"));
    cout << s << endl; // OK

    return 0;
}