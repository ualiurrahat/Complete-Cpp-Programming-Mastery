/**
 * @file 06_structConstructor.cpp
 * @brief Demonstrates use of constructors inside structures.
 *
 * -------------------- Problem Statement --------------------
 * Create a `full_name` structure with a constructor that initializes
 * `first` and optionally `last` name fields.
 * -----------------------------------------------------------
 */

#include <iostream>
using namespace std;

// ---------------------- Structure Definition ----------------------
struct full_name
{
    string first, middle, last;

    // Constructor with default argument for last name
    full_name(string _first, string _last = "")
    {
        first = _first;
        last = _last;
        middle = "";
    }
};

// ---------------------- Main Function ----------------------
int main()
{
    full_name my_name("ali");
    cout << my_name.first << "\n";

    full_name his_name = full_name("mostafa", "ibrahim");
    cout << his_name.last;

    return 0;
}
