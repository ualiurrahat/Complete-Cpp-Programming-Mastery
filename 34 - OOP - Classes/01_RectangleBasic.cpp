/**
 * @file 01_RectangleBasic.cpp
 * @brief Demonstrates the most basic OOP class: a Rectangle with private members,
 *        a default constructor, explicit setters/getters and two simple methods.
 *
 * The class encapsulates width and height, forces the user to set them via
 * SetWidth()/SetHeight() and provides ComputeArea() and ComputePerimeter().
 * No initialisation-list is used – values are assigned inside the constructor body.
 */

#include <iostream>

class Rectangle
{
private:
    double width;  ///< Width of the rectangle (private)
    double height; ///< Height of the rectangle (private)

public:
    /** @brief Default constructor – initialises both dimensions to 0. */
    Rectangle()
    {
        width = height = 0.0;
    }

    /** @brief Parameterised constructor – initialises with given dimensions. */
    Rectangle(double w, double h)
    {
        width = w;
        height = h;
    }

    /** @brief Calculates the area of the rectangle. */
    double ComputeArea() const
    {
        return width * height;
    }

    /** @brief Calculates the perimeter of the rectangle. */
    double ComputePerimeter() const
    {
        return 2.0 * (width + height);
    }

    // --------------------------------------------------------------------
    // Setters & Getters
    // --------------------------------------------------------------------
    /** @brief Returns the current height. */
    double GetHeight() const { return height; }

    /** @brief Sets a new height (no validation). */
    void SetHeight(double h) { height = h; }

    /** @brief Returns the current width. */
    double GetWidth() const { return width; }

    /** @brief Sets a new width (no validation). */
    void SetWidth(double w) { width = w; }
};

int main()
{
    Rectangle r1; // default ctor → 0×0
    r1.SetWidth(5.0);
    r1.SetHeight(10.0);
    std::cout << r1.ComputeArea() << "\n"; // 50

    Rectangle r2(10.0, 3.0);               // parameterised ctor
    std::cout << r2.ComputeArea() << "\n"; // 30
    r2.SetWidth(0.0);
    std::cout << r2.ComputeArea() << "\n"; // 0

    return 0;
}