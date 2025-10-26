/**
 * @file 04_RectangleDefaultCtor.cpp
 * @brief Shows that a user-defined constructor **does not disable** the default one
 *        **if you explicitly provide it**.
 *
 * Rule: If you define *any* constructor, the compiler **does not** generate a default one.
 * So we must write `Rectangle()` ourselves to allow `Rectangle r1;`.
 */

#include <iostream>
using namespace std;

class Rectangle
{
private:
    double width;  ///< Width of the rectangle
    double height; ///< Height of the rectangle

public:
    /** @brief Default constructor – required for `Rectangle obj;` */
    Rectangle() : width(0.0), height(0.0) {}

    /**
     * @brief Parameterized constructor – sets custom dimensions.
     * @param w Initial width
     * @param h Initial height
     */
    Rectangle(double w, double h) : width(w), height(h) {}

    double ComputeArea() const
    {
        return width * height;
    }

    double ComputePerimeter() const
    {
        return 2.0 * (width + height);
    }

    // Getters
    double GetHeight() const { return height; }
    double GetWidth() const { return width; }

    // Setters
    void SetHeight(double h) { height = h; }
    void SetWidth(double w) { width = w; }
};

int main()
{
    Rectangle r1; // OK: uses explicit default ctor
    r1.SetWidth(5.0);
    r1.SetHeight(10.0);
    cout << r1.ComputeArea() << "\n"; // 50

    Rectangle r2(3.0, 4.0);           // uses parameterized ctor
    cout << r2.ComputeArea() << "\n"; // 12

    return 0;
}