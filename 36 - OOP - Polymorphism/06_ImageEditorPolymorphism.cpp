// <DOCUMENT filename="06_ImageEditorPolymorphism.cpp">
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

/**
 * @file 06_ImageEditorPolymorphism.cpp
 * @brief Full editor with cloning, drawing, polymorphism.
 *
 * Features:
 * - `Shape::Clone()` → virtual copy constructor
 * - `ImageEditor` stores `Shape*` → draws any shape
 * - `AddShape()` uses cloning → type-safe copy
 */

class Point
{
    double x, y;

public:
    Point(double x, double y) : x(x), y(y) {}
    string ToString() const
    {
        ostringstream oss;
        oss << "(" << x << ", " << y << ")";
        return oss.str();
    }
};

class Shape
{
protected:
    int color;

public:
    Shape(int c) : color(c) {}
    virtual int ComputeArea() const { return 0; }
    virtual void Draw() const { cout << "Area: " << ComputeArea() << "\n"; }
    virtual Shape *Clone() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape
{
    Point tl, br;

public:
    Rectangle(int c, const Point &tl, const Point &br) : Shape(c), tl(tl), br(br) {}
    int ComputeArea() const override { return 10; }
    void Draw() const override
    {
        Shape::Draw();
        cout << "Rect: " << tl.ToString() << " - " << br.ToString() << "\n";
    }
    Shape *Clone() const override { return new Rectangle(*this); }
};

class Circle : public Shape
{
    Point center;
    double radius;

public:
    Circle(int c, const Point &ctr, double r) : Shape(c), center(ctr), radius(r) {}
    int ComputeArea() const override { return 20; }
    void Draw() const override
    {
        Shape::Draw();
        cout << "Circle: " << center.ToString() << " r=" << radius << "\n";
    }
    Shape *Clone() const override { return new Circle(*this); }
};

class ImageEditor
{
    vector<Shape *> shapes;

public:
    void AddShape(const Shape &s) { shapes.push_back(s.Clone()); }
    virtual void Draw() const
    {
        cout << "=== Drawing ===\n";
        for (const auto *s : shapes)
            s->Draw();
    }
    virtual ~ImageEditor()
    {
        for (auto *s : shapes)
            delete

                s;
    }
};

int main()
{
    ImageEditor editor;
    editor.AddShape(Rectangle(1, Point(0, 0), Point(5, 5)));
    editor.AddShape(Circle(2, Point(10, 10), 3));
    editor.Draw();
    return 0;
}