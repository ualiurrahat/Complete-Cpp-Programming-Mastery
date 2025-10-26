/**
 * @file 02_FunctionOverloading.cpp
 * @brief Homework: Demonstrate function overloading with set() and get().
 *
 * @section problem Problem Statement
 * Create a class `MyClass` with:
 * - Private members: `x`, `y`, `z`
 * - Overloaded `set()` methods:
 *   - `set(int)`
 *   - `set(double)`
 *   - `set(int, int)`
 *   - `set(int, int, int)`
 * - Overloaded `get()`:
 *   - `get(int&)` → returns x
 *   - `get(int&, int&)` → returns x, y
 *
 * Show output: A, B, C, D
 *
 * @section intuition Intuition
 * Overloading allows same function name for different types/signatures.
 * Compiler picks correct version based on **arguments**.
 * Improves API usability — user calls `set(value)` naturally.
 *
 * @section logic Logic & Flow
 * 1. Define multiple `set()` with different parameter lists
 * 2. Each prints unique letter
 * 3. `main()` calls in order → A B C D
 */

#include <iostream>
using namespace std;

class MyClass
{
private:
    int x = 0, y = 0, z = 0;

public:
    void set(int x) { cout << "A\n"; }
    void set(double x) { cout << "B\n"; }
    void set(int x, int y) { cout << "C\n"; }
    void set(int x, int y, int z) { cout << "D\n"; }

    void get(int &a)
    {
        a = this->x;
        cout << "E\n";
    }

    void get(int &a, int &b)
    {
        a = x;
        b = y;
        cout << "F\n";
    }
};

int main()
{
    MyClass m;
    m.set(1);       // A
    m.set(1.5);     // B
    m.set(1, 2);    // C
    m.set(1, 2, 3); // D

    return 0;
}