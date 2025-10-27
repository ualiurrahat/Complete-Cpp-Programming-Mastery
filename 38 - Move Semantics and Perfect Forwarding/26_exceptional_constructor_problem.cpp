// 26_exponential_constructors_problem.cpp
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Demonstrates the **impracticality** of writing constructors for all lvalue/rvalue combinations.
 *
 * @details
 * - For 3 string parameters: 2^3 = 8 constructors needed.
 * - Exponential growth → impossible to maintain.
 * - Solution: **Perfect Forwarding** with templates.
 */
class Student
{
private:
    string full_name, nick_name, address;

public:
    // 8 constructors to support all combinations of (const string&, string&&)
    Student(string &&full_name, string &&nick_name, string &&address)
    {
        cout << "RRR\n";
    }

    Student(string &&full_name, string &&nick_name, const string &address)
    {
        cout << "RRL\n";
    }

    Student(string &&full_name, const string &nick_name, string &&address)
    {
        cout << "RLR\n";
    }

    Student(string &&full_name, const string &nick_name, const string &address)
    {
        cout << "RLL\n";
    }

    Student(const string &full_name, string &&nick_name, string &&address)
    {
        cout << "LRR\n";
    }

    Student(const string &full_name, string &&nick_name, const string &address)
    {
        cout << "LRL\n";
    }

    Student(const string &full_name, const string &nick_name, string &&address)
    {
        cout << "LLR\n";
    }

    Student(const string &full_name, const string &nick_name, const string &address)
    {
        cout << "LLL\n";
    }
};

int main()
{
    // prvalue → binds to string&& → RRR
    Student("", "", "");

    string L = "home";
    // full_name: prvalue → &&, nick_name: lvalue → const&, address: prvalue → &&
    Student("", L, "");

    return 0;
}