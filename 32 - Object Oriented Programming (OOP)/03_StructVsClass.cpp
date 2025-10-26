/**
 * @file 03_StructVsClass.cpp
 * @brief Compares struct (public by default) vs class (private by default).
 *
 * In C++, `struct` and `class` are nearly identical — the **only difference**
 * is default access: `struct` → public, `class` → private.
 *
 * @section intuition Intuition
 * Use `struct` for **simple data containers** (like C structs).
 * Use `class` when you want **encapsulation** and **behavior control**.
 *
 * @section logic Logic & Flow
 * 1. `Rectangle` defined as `struct`
 * 2. All members public by default
 * 3. Direct access to `.width`, `.height` → no data protection
 *
 * @warning This violates encapsulation! Use only for POD (Plain Old Data).
 */

#include <iostream>
using namespace std;

struct Rectangle
{
    double width;  ///< Public by default in struct
    double height; ///< Public by default in struct

    /// Default constructor
    Rectangle()
    {
        width = height = 0;
    }

    /// Parameterized constructor
    Rectangle(double width_, double height_)
    {
        width = width_, height = height_;
    }

    double ComputeArea()
    {
        return width * height;
    }

    double ComputePerimeter()
    {
        return 2 * (width + height);
    }
};

int main()
{
    Rectangle r1;
    r1.width = 5; // Direct access — allowed in struct
    r1.height = 10;
    cout << r1.ComputeArea() << "\n"; // 50

    Rectangle r2(10, 3);
    cout << r2.ComputeArea() << "\n"; // 30
    r2.width = 0;
    cout << r2.ComputeArea() << "\n"; // 0

    return 0;
}