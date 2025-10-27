// 33_move_in_ctor_pitfall.cpp
#include <iostream>
#include <string>
#include <utility>
using namespace std;

/**
 * @brief DANGER: Using `std::move` on parameters passed by value.
 *
 * @details
 * - Parameters are **lvalues** inside constructor.
 * - `std::move` converts them to xvalue → **moves from them**.
 * - But caller passed copies → **empty strings**!
 */
class Student
{
private:
    string full_name, nick_name, address;

public:
    Student(string full_name, string nick_name, string address)
        : full_name(std::move(full_name)), // Moves from parameter!
          nick_name(std::move(nick_name)),
          address(std::move(address))
    {
    }
};

int main()
{
    string L = "hello";
    Student("x", L, "y");

    // L is now empty! Moved from in ctor
    cout << "L after: '" << L << "'\n"; // empty

    return 0;
}