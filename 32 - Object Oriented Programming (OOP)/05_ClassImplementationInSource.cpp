/**
 * @file 05_ClassImplementationInSource.cpp
 * @brief Implements the Rectangle class declared in rectangle.h.
 *
 * This file contains the **method definitions** using scope resolution `::`.
 *
 * @section intuition Intuition
 * Users compile `main.cpp + rectangle.cpp` → linker connects calls.
 * Changing implementation doesn't require recompiling users of the class
 * (if interface unchanged).
 *
 * @section logic Logic & Flow
 * 1. Include header for class declaration
 * 2. Define each method outside class body
 * 3. Use `Rectangle::` to specify scope
 */

#include "rectangle.h" // Must include declaration

Rectangle::Rectangle()
{
    width = height = 0;
}

Rectangle::Rectangle(double width_, double height_)
{
    width = width_, height = height_;
}

double Rectangle::ComputeArea()
{
    return width * height;
}

double Rectangle::ComputePerimeter()
{
    return 2 * (width + height);
}

double Rectangle::GetHeight()
{
    return height;
}

void Rectangle::SetHeight(double height)
{
    this->height = height;
}

double Rectangle::GetWidth()
{
    return width;
}

void Rectangle::SetWidth(double width)
{
    this->width = width;
}