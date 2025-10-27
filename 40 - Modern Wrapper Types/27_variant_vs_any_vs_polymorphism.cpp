// 27_variant_vs_any_vs_polymorphism.cpp
/**
 * @file 27_variant_vs_any_vs_polymorphism.cpp
 * @brief Comparison: std::variant vs std::any vs virtual polymorphism.
 *
 * | Feature               | variant<Ts...>         | any                  | unique_ptr<Base>     |
 * |-----------------------|------------------------|----------------------|----------------------|
 * | Type Safety           | Compile-time           | Runtime              | Compile-time (vtable) |
 * | Possible Types        | Closed set             | Any copyable         | Inheritance hierarchy |
 * | Memory Overhead       | sizeof(largest) + index| Dynamic allocation   | Pointer + vtable     |
 * | Construction          | in_place, emplace      | make_any, emplace    | new/make_unique      |
 * | Use Case              | Known alternatives     | Unknown/dynamic      | Open extension       |
 *
 * This file demonstrates all three side-by-side.
 */

#include <iostream>
#include <variant>
#include <any>
#include <memory>
#include <string>
using namespace std;

// === Polymorphism ===
struct Shape
{
    virtual ~Shape() = default;
    virtual double area() const = 0;
};
struct Circle : Shape
{
    double r;
    Circle(double r) : r(r) {}
    double area() const override { return 3.14 * r * r; }
};
struct Square : Shape
{
    double s;
    Square(double s) : s(s) {}
    double area() const override { return s * s; }
};

// === variant ===
using ShapeVar = variant<Circle, Square>;

// === any ===
any shape_any;

void demo_polymorphism()
{
    cout << "\n--- Polymorphism ---\n";
    unique_ptr<Shape> s = make_unique<Circle>(2);
    cout << "Circle area: " << s->area() << endl;
}

void demo_variant()
{
    cout << "\n--- std::variant ---\n";
    ShapeVar sv = Circle{3};
    auto area_visitor = [](const auto &shape)
    { cout << "Area: " << shape.area() << endl; };
    visit(area_visitor, sv);
}

void demo_any()
{
    cout << "\n--- std::any ---\n";
    shape_any = Circle{4};
    if (shape_any.type() == typeid(Circle))
    {
        cout << "Area: " << any_cast<Circle>(shape_any).area() << endl;
    }
}

int main()
{
    demo_polymorphism();
    demo_variant();
    demo_any();
    return 0;
}