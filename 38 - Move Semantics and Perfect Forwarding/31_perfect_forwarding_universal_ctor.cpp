// 31_perfect_forwarding_universal_ctor.cpp
#include <iostream>
#include <string>
#include <utility>
using namespace std;

/**
 * @brief Universal constructor using perfect forwarding.
 *
 * @details
 * - One constructor handles **all** combinations of lvalue/rvalue.
 * - Uses separate template parameters per argument → **perfect forwarding**.
 * - `std::forward<T>(arg)` preserves value category.
 */
class Student
{
private:
    string full_name, nick_name, address;

public:
    template <typename T1, typename T2, typename T3>
    Student(T1 &&full_name, T2 &&nick_name, T3 &&address)
        : full_name(std::forward<T1>(full_name)),
          nick_name(std::forward<T2>(nick_name)),
          address(std::forward<T3>(address))
    {
        // No body needed — members initialized above
    }
};

int main()
{
    string L = "home";

    Student("", "", ""); // RRR: all prvalues → moved
    Student("", L, "");  // RLR: middle is lvalue → copied

    return 0;
}