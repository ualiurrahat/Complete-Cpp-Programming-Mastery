/**
 * @file 29_StaticCounter.cpp
 * @brief Uses `static` member to count total `Employee` objects.
 *
 * - `employees_count` is **shared** across all instances
 * - Incremented in constructor, accessible via `static` getter
 * - Even `static` local objects count!
 */

#include <iostream>
#include <vector>
using namespace std;

class Employee
{
private:
    string name;
    static int employees_count; ///< Shared counter

public:
    /** @brief Constructor – increments global count. */
    Employee(string name_val) : name(move(name_val))
    {
        ++employees_count;
    }

    /**
     * @brief Returns total number of Employee objects created.
     * @return Current count
     */
    static int GetEmployeeCount()
    {
        return employees_count;
    }

    const string &GetName() const { return name; }
};

// Definition of static member
int Employee::employees_count = 0;

int main()
{
    Employee most("Mostafa");
    Employee mona("Mona");
    static Employee belal("Belal"); // Also counts!

    cout << Employee::GetEmployeeCount() << "\n"; // 3

    return 0;
}