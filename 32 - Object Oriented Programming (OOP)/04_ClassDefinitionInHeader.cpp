/**
 * @file 04_ClassDefinitionInHeader.cpp
 * @brief Header file defining the Rectangle class interface.
 *
 * Separating **declaration** (in `.h`) from **definition** (in `.cpp`) is
 * a best practice in C++ for larger projects.
 *
 * @section intuition Intuition
 * Header files provide the **contract** — what the class offers.
 * Users include this file to use the class without seeing implementation.
 *
 * @note Include guards (`#ifndef`) prevent double inclusion.
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

class Rectangle
{
private:
    double width;  ///< Width of rectangle
    double height; ///< Height of rectangle

public:
    /// Default constructor: initializes to 0x0
    Rectangle();

    /// Parameterized constructor
    Rectangle(double width_, double height_);

    /// @return Area of rectangle
    double ComputeArea();

    /// @return Perimeter of rectangle
    double ComputePerimeter();

    /// @return Current height
    double GetHeight();

    /// @param height New height value
    void SetHeight(double height);

    /// @return Current width
    double GetWidth();

    /// @param width New width value
    void SetWidth(double width);
};

#endif /* RECTANGLE_H_ */