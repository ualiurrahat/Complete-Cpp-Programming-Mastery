/**
 * @file 05_RectangleInClassInit.cpp
 * @brief Demonstrates C++11 in-class member initializers.
 *
 * Members can be given default values directly at declaration.
 * This is especially useful when:
 *   - Multiple constructors exist
 *   - You want a guaranteed default even if no constructor is called
 *
 * Here, every Rectangle starts as 10x20 unless explicitly changed.
 */

#include <iostream>
using namespace std;

class Rectangle
{
private:
    double width = 10.0;  ///< Default width: 10.0 (C++11)
    double height = 20.0; ///< Default height: 20.0

public:
    /** @brief Computes area using current width and height. */
    double ComputeArea() const
    {
        return width * height;
    }

    /** @brief Computes perimeter. */
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
    Rectangle r1;                     // Uses in-class defaults → 10×20
    cout << r1.ComputeArea() << "\n"; // 200

    r1.SetWidth(5.0);
    cout << r1.ComputeArea() << "\n"; // 100 (5×20)

    return 0;
}