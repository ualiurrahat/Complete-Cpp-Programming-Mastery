/**
 * @file 23_RectangleConstObject.cpp
 * @brief Demonstrates behavior of `const` objects and `const` member functions.
 *
 * - A `const Rectangle` can only call `const` member functions
 * - Non-const functions like `SetWidth()` are **blocked**
 * - `ComputeArea()` is marked `const` → safe to call
 */

#include <iostream>
#include <vector>
using namespace std;

class Rectangle
{
private:
    double width;
    double height;

public:
    /** @brief Constructor with default dimensions. */
    Rectangle(double w = 0.0, double h = 0.0) : width(w), height(h) {}

    /** @brief Computes area — marked `const` to allow use on const objects. */
    double ComputeArea() const
    {
        // width = 1;  // ERROR: cannot modify members in const function
        return width * height;
    }

    // --------------------- Getters (const) ---------------------
    double GetHeight() const { return height; }
    double GetWidth() const { return width; }

    // --------------------- Setters (non-const) -----------------
    void SetHeight(double h) { height = h; }
    void SetWidth(double w) { width = w; }
};

int main()
{
    Rectangle r1(2, 3);
    r1.SetWidth(10); // OK: non-const object
    cout << "r1 area: " << r1.ComputeArea() << "\n";

    const Rectangle r2(4, 5);
    cout << "r2 area: " << r2.ComputeArea() << "\n"; // OK: const member
    // r2.SetWidth(10);        // ERROR: const object

    return 0;
}