/**
 * @file 10_friendFunctionDistance.cpp
 * @brief Demonstrates the use of Friend Functions in C++.
 *
 * Friend Function: A function that is not a member of a class
 * but can access its private members.
 * Here, we use a friend function to calculate distance between two points.
 */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/**
 * @class Point
 * @brief Represents a 2D point with x and y coordinates.
 */
class Point
{
    int x; ///< x-coordinate
    int y; ///< y-coordinate

    // Declare friend function
    friend double distance(Point, Point);

public:
    /// Constructor
    Point(int a, int b)
    {
        x = a;
        y = b;
    }

    /// Displays the point coordinates
    void displayPoint()
    {
        cout << "Your point is (" << x << ", " << y << ")" << endl;
    }
};

/**
 * @brief Calculates the Euclidean distance between two points.
 * @param d1 First point
 * @param d2 Second point
 * @return Distance between d1 and d2
 */
double distance(Point d1, Point d2)
{
    double delta_x = d2.x - d1.x;
    double delta_y = d2.y - d1.y;
    return sqrt(pow(delta_x, 2) + pow(delta_y, 2));
}

// ------------------------------- Main -------------------------------
int main()
{
    Point d1(1, 4);
    Point d2(5, 1);

    d1.displayPoint(); // (1, 4)
    d2.displayPoint(); // (5, 1)

    double d = distance(d1, d2);
    cout << "The distance is " << d << endl; // Expected: 5

    Point c1(1, 4);
    double e = distance(d1, c1);
    cout << "The distance is " << e << endl; // Expected: 0

    return 0;
}
