/**
 * @file 08_PrecisionAndRounding.cpp
 * @brief Explores how `setprecision` controls rounding in different modes.
 *
 * Key Insight:
 * - `setprecision(n)` in **fixed** mode → n digits **after** decimal
 * - In **default/scientific** → n **significant digits**
 * - Rounding: typically "round half away from zero" or banker's rounding
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double c = 3.14159;

    cout << setprecision(5) << c << '\n'; // 3.1416
    cout << setprecision(9) << c << '\n'; // 3.14159

    cout << fixed;
    cout << setprecision(5) << c << '\n'; // 3.14159
    cout << setprecision(9) << c << '\n'; // 3.141590000

    cout << "\nRounding examples:\n";
    double value = 1.21658;

    cout << setprecision(7) << value << "\n"; // 1.2165800
    cout << setprecision(6) << value << "\n"; // 1.216580
    cout << setprecision(5) << value << "\n"; // 1.21658
    cout << setprecision(4) << value << "\n"; // 1.2166
    cout << setprecision(3) << value << "\n"; // 1.217
    cout << setprecision(2) << value << "\n"; // 1.22
    cout << setprecision(1) << value << "\n"; // 1.2
    cout << setprecision(0) << value << "\n"; // 1

    cout << setprecision(3) << 1.21648 << "\n"; // 1.216

    return 0;
}