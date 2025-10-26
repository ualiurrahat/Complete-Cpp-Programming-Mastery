/**
 * @file 25_RectangleConstMembers.cpp
 * @brief Shows how `const` member variables **must** be initialized in the initializer list.
 *
 * - `tmp1` → in-class initialization (C++11)
 * - `tmp2` → **must** use member initializer list
 * - Cannot assign in constructor body
 */

#include <iostream>
#include <vector>
using namespace std;

class Rectangle
{
private:
    double width;
    double height;
    const int tmp1 = 10; ///< In-class const initialization
    const int tmp2;      ///< Must be initialized in ctor initializer list

public:
    /** @brief Constructor — `tmp2` initialized in list. */
    Rectangle(double w = 0.0, double h = 0.0)
        : width(w), height(h), tmp2(6)
    {
        // tmp2 = 6;  // ERROR: cannot assign to const member
    }

    double ComputeArea() const { return width * height; }

    double GetHeight() const { return height; }
    void SetHeight(double h) { height = h; }
    double GetWidth() const { return width; }
    void SetWidth(double w) { width = w; }

    int GetTmp1() const { return tmp1; }
    int GetTmp2() const { return tmp2; }
};

int main()
{
    Rectangle r(3, 4);
    cout << "Area: " << r.ComputeArea() << "\n";
    cout << "tmp1: " << r.GetTmp1() << ", tmp2: " << r.GetTmp2() << "\n";

    return 0;
}