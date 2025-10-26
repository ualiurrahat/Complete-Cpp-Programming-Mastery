/**
 * @file 22_DeletedFunction.cpp
 * @brief Deletes a member function overload to avoid dangerous implicit conversions.
 *
 * - `Hello(double)` is **deleted**
 * - Prevents accidental call with floating-point
 * - Forces user to be explicit
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Employee
{
private:
    int *salary{nullptr};
    string name;

public:
    Employee() = default;

    void Hello(int x)
    {
        cout << "Hello with int: " << x << "\n";
    }

    /** @brief Deleted: no double version. */
    void Hello(double x) = delete;

    Employee(int salary_val, string name_val)
        : salary(new int{salary_val}), name(move(name_val))
    {
    }

    ~Employee()
    {
        delete salary;
        salary = nullptr;
    }

    const string &GetName() const { return name; }
};

int main()
{
    Employee e1(10, "Mostafa");

    e1.Hello(10); // OK
    // e1.Hello(10.5);     // ERROR: deleted function

    return 0;
}