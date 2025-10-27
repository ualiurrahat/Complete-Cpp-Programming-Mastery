// 38_deleted_copy_move.cpp
#include <iostream>
using namespace std;

/**
 * @brief Non-copyable but movable type.
 *
 * @details
 * - C++17 allows copy elision even if copy is deleted,
 *   BUT move constructor must be accessible.
 * - If BOTH copy and move are deleted → return-by-value is ill-formed.
 */
class Employee
{
public:
    Employee() { cout << "Employee()\n"; }

    // Delete copy
    Employee(const Employee &) = delete;

    // Allow move (defaulted)
    Employee(Employee &&) = default;

    ~Employee() { cout << "~Employee()\n"; }
};

/* ========================= NOW COMPILES ========================= */

Employee GetPrvalue()
{
    return Employee{}; // OK: prvalue → elided, move ctor accessible
}

Employee GetLocal()
{
    Employee e;
    return e; // OK: NRVO or move, move ctor accessible
}

Employee GetMoved()
{
    Employee e;
    return std::move(e); // OK: explicit move
}

/* ================================================================ */

int main()
{
    Employee e1 = GetPrvalue(); // No copy, no move → direct construction
    Employee e2 = GetLocal();   // NRVO or move
    Employee e3 = GetMoved();   // Move

    return 0;
}