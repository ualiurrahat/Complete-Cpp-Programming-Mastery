/**
 * @file 02_RectangleDelegation.cpp
 * @brief Shows constructor delegation and the use of member-initialiser lists.
 *
 * - The default constructor delegates to the two-parameter constructor.
 * - All constructors initialise members directly in the initialiser list
 *   (the most efficient way).
 * - A third constructor overload creates a rectangle with a given width and
 *   height = 0.
 */

#include <iostream>

class Rectangle
{
private:
    double width;  ///< Width of the rectangle
    double height; ///< Height of the rectangle

public:
    /** @brief Default constructor – delegates to the (width,height) ctor. */
    Rectangle() : Rectangle(0.0, 0.0) {}

    /** @brief Two-parameter constructor – direct initialisation. */
    Rectangle(double w, double h) : width(w), height(h) {}

    /** @brief Single-parameter overload – height defaults to 0. */
    Rectangle(double w) : width(w), height(0.0) {}

    double ComputeArea() const { return width * height; }
    double ComputePerimeter() const { return 2.0 * (width + height); }

    double GetHeight() const { return height; }
    void SetHeight(double h) { height = h; }
    double GetWidth() const { return width; }
    void SetWidth(double w) { width = w; }
};

int main()
{
    Rectangle r1; // default → 0×0
    r1.SetWidth(5.0);
    r1.SetHeight(10.0);
    std::cout << r1.ComputeArea() << "\n"; // 50

    Rectangle r2(10.0, 3.0);
    std::cout << r2.ComputeArea() << "\n"; // 30
    r2.SetWidth(0.0);
    std::cout << r2.ComputeArea() << "\n"; // 0

    return 0;
}