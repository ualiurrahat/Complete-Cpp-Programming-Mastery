/**
 * @file 06_RectangleDestructor.cpp
 * @brief Illustrates when and how a destructor is called.
 *
 * - The destructor `~Rectangle()` is invoked **automatically** when an object
 *   goes out of scope (end of `main()` here).
 * - This is the foundation of **RAII** (Resource Acquisition Is Initialization).
 * - Even without dynamic memory, destructors are useful for logging, cleanup,
 *   or ensuring invariants.
 */

#include <iostream>
using namespace std;

class Rectangle
{
private:
    double width;
    double height;

public:
    /** @brief Default constructor – initializes to 0×0. */
    Rectangle() : width(0.0), height(0.0)
    {
        cout << "Rectangle constructed (default)\n";
    }

    /** @brief Parameterized constructor – explicit dimensions. */
    Rectangle(double w, double h) : width(w), height(h)
    {
        cout << "Rectangle constructed (" << w << "x" << h << ")\n";
    }

    /** @brief Destructor – called automatically at end of scope. */
    ~Rectangle()
    {
        cout << "Destructor called for Rectangle ("
             << width << "x" << height << ")\n";
    }

    double ComputeArea() const
    {
        return width * height;
    }

    double ComputePerimeter() const
    {
        return 2.0 * (width + height);
    }

    double GetHeight() const { return height; }
    void SetHeight(double h) { height = h; }
    double GetWidth() const { return width; }
    void SetWidth(double w) { width = w; }
};

int main()
{
    cout << "=== Start of main ===\n";

    Rectangle r1; // default ctor
    r1.SetWidth(5.0);
    r1.SetHeight(10.0);
    cout << "Area: " << r1.ComputeArea() << "\n"; // 50

    {
        cout << "\n--- Inner block ---\n";
        Rectangle r2(4.0, 6.0);                       // parameterized ctor
        cout << "Area: " << r2.ComputeArea() << "\n"; // 24
        // r2 destroyed here when block ends
    }

    cout << "\nBack in main\n";
    // r1 destroyed here when main ends

    cout << "=== End of main ===\n";
    return 0;
}