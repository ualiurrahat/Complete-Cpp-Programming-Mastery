/**
 * @file 06_SingleFileClassDemo.cpp
 * @brief Complete Rectangle class in a single file (for small programs).
 *
 * For learning or small tools, defining class and `main()` in one file
 * is acceptable and clearer.
 *
 * @section intuition Intuition
 * This avoids header/source split complexity while teaching OOP.
 * Same principles apply: private data, public interface.
 */

#include <iostream>
using namespace std;

class Rectangle
{
private:
    double width;
    double height;

public:
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

    // Getters
    double GetHeight() { return height; }
    double GetWidth() { return width; }

    // Setters
    void SetHeight(double height) { this->height = height; }
    void SetWidth(double width) { this->width = width; }
};

int main()
{
    Rectangle r1;
    r1.SetWidth(5);
    r1.SetHeight(10);
    cout << r1.ComputeArea() << "\n"; // 50

    Rectangle r2(10, 3);
    cout << r2.ComputeArea() << "\n"; // 30
    r2.SetWidth(0);
    cout << r2.ComputeArea() << "\n"; // 0

    return 0;
}