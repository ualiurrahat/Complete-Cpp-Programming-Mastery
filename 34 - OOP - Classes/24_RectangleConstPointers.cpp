/**
 * @file 24_RectangleConstPointers.cpp
 * @brief Explores `const` correctness with pointers.
 *
 * - `const Rectangle*` → **data is const**, pointer can change
 * - `Rectangle* const` → **pointer is const**, data can change
 * - `const Rectangle* const` → both **immutable**
 */

#include <iostream>
#include <vector>
using namespace std;

class Rectangle
{
private:
    double width;
    double height;

public:
    Rectangle(double w = 0.0, double h = 0.0) : width(w), height(h) {}

    double ComputeArea() const { return width * height; }

    double GetHeight() const { return height; }
    double GetWidth() const { return width; }
    void SetHeight(double h) { height = h; }
    void SetWidth(double w) { width = w; }
};

int main()
{
    Rectangle r1(2, 3);

    // 1. Pointer to const data
    const Rectangle *r2 = new Rectangle(4, 5);
    // r2->SetWidth(10);     // ERROR: data is const
    r2 = &r1; // OK: pointer can change

    // 2. Const pointer to mutable data
    Rectangle *const r3 = new Rectangle(1, 2);
    r3->SetWidth(10.2); // OK: data is mutable
    // r3 = &r1;             // ERROR: pointer is const

    // 3. Both const
    const Rectangle *const r4 = new Rectangle(1, 2);
    // r4->SetWidth(10);     // ERROR
    // r4 = &r1;             // ERROR

    // 4. Pointer to existing object
    const Rectangle *const r5 = &r1; // OK

    cout << "r2 area: " << r2->ComputeArea() << "\n";
    cout << "r3 width: " << r3->GetWidth() << "\n";

    delete r2;
    delete r3;
    delete r4;

    return 0;
}