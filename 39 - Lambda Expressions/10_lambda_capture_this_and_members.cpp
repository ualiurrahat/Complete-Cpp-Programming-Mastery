/**
 * @file 10_lambda_capture_this_and_members.cpp
 * @brief Capturing `this` in member functions.
 *
 * To access class members inside a lambda defined in a member function,
 * you must capture `this` (or use `[this]` in C++17+).
 *
 * Note: Capturing `this` means the lambda holds a pointer to the object.
 * Object must outlive the lambda.
 */

#include <iostream>
#include <vector>
using namespace std;

class Employee
{
private:
    int salary = 0;
    string name;

public:
    void hello()
    {
        int a = 1, b = 5;

        // Capture 'this' to access 'salary'
        auto f = [&a, this, b]()
        {
            salary = 20; // OK: 'this->salary'
            // name = "John"; // also allowed
        };
        f();
        cout << salary; // Output: 20
    }
};

int main()
{
    Employee emp;
    emp.hello();
    return 0;
}