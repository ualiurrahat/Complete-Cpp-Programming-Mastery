// <DOCUMENT filename="04_PolymorphicShapeArea.cpp">
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

/**
 * @file 04_PolymorphicShapeArea.cpp
 * @brief Real-world example: `Shape` base with polymorphic `Area()`.
 *
 * Design:
 * - `process(Shape*)` works with ANY shape
 * - `Area()` is virtual → correct version called
 * - Non-virtual `GetShapeName()` → compile-time
 */

class Shape
{
private:
    string name;

public:
    Shape(string name) : name(name) {}

    virtual int Area()
    {
        throw logic_error("Area() not implemented!");
    }

    string GetShapeName() const { return name; }
    virtual ~Shape() = default;
};

class Rectangle : public Shape
{
    int wid, height;

public:
    Rectangle(string name, int w, int h) : Shape(name), wid(w), height(h) {}
    int Area() override { return wid * height; }
};

void process(Shape *shape)
{
    cout << "Shape: " << shape->GetShapeName()
         << ", Area: " << shape->Area() << "\n";
}

int main()
{
    Rectangle r("Rect", 4, 5);
    process(&r); // Shape: Rect, Area: 20
    return 0;
}