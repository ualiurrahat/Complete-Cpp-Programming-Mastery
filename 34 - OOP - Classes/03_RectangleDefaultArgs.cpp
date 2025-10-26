/**
 * @file 03_RectangleDefaultArgs.cpp
 * @brief Demonstrates correct use of default arguments in constructors.
 *
 * Instead of two identical constructors (which cause ambiguity),
 * we provide **one** constructor with default parameters.
 * This allows:
 *   - Rectangle()          → 0×0
 *   - Rectangle(w)         → w×0
 *   - Rectangle(w, h)      → w×h
 *
 * No overload ambiguity → compiles cleanly.
 */

#include <iostream>
using namespace std;

class Rectangle
{
private:
    double width;  ///< Width of the rectangle
    double height; ///< Height of the rectangle

public:
    /**
     * @brief Single constructor with default arguments.
     * @param w Width (defaults to 0.0)
     * @param h Height (defaults to 0.0)
     */
    Rectangle(double w = 0.0, double h = 0.0) : width(w), height(h) {}

    /** @brief Computes area: width × height */
    double ComputeArea() const
    {
        return width * height;
    }

    /** @brief Computes perimeter: 2×(width + height) */
    double ComputePerimeter() const
    {
        return 2.0 * (width + height);
    }

    // --------------------- Getters ---------------------
    double GetHeight() const { return height; }
    double GetWidth() const { return width; }

    // --------------------- Setters ---------------------
    void SetHeight(double h) { height = h; }
    void SetWidth(double w) { width = w; }
};

int main()
{
    Rectangle r1;                     // uses defaults → 0×0
    cout << r1.ComputeArea() << "\n"; // 0

    Rectangle r2(5.0);                // width=5, height=0
    cout << r2.ComputeArea() << "\n"; // 0

    Rectangle r3(4.0, 6.0);           // explicit width & height
    cout << r3.ComputeArea() << "\n"; // 24

    return 0;
}