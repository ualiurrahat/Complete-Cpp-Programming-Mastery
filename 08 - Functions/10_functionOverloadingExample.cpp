/**
 * @file 10_functionOverloadingExample.cpp
 * @brief Demonstrates function overloading for calculating volumes.
 */

#include <iostream>
using namespace std;

/**
 * @brief Calculates volume of a cube.
 */
int volume(int a)
{
    return a * a * a;
}

/**
 * @brief Calculates volume of a cylinder.
 */
float volume(int r, int h)
{
    return 3.14 * r * r * h;
}

/**
 * @brief Calculates volume of a cuboid.
 */
int volume(int l, int b, int h)
{
    return l * b * h;
}

int main()
{
    cout << "Volume of cube (side = 4): " << volume(4) << endl;
    cout << "Volume of cylinder (r = 3, h = 8): " << volume(3, 8) << endl;
    cout << "Volume of cuboid (4x3x7): " << volume(4, 3, 7) << endl;

    return 0;
}
