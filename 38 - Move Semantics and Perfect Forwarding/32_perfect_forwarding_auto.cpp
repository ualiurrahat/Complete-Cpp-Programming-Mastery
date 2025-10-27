// 32_perfect_forwarding_auto.cpp
#include <iostream>
#include <string>
#include <utility>
using namespace std;

/**
 * @brief C++23 `auto` parameters for perfect forwarding (shorter syntax).
 *
 * @details
 * - `auto &&x` in function parameters → forwarding reference.
 * - `decltype(x)` deduces exact type.
 * - Same effect as `template<typename T> void f(T&& x)`
 */
class Student
{
private:
    string full_name, nick_name, address;

public:
    Student(auto &&full_name, auto &&nick_name, auto &&address)
        : full_name(std::forward<decltype(full_name)>(full_name)),
          nick_name(std::forward<decltype(nick_name)>(nick_name)),
          address(std::forward<decltype(address)>(address))
    {
    }
};

int main()
{
    string L = "home";
    Student("", "", ""); // RRR
    Student("", L, "");  // RLR

    return 0;
}