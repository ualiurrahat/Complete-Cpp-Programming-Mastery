// 02_lvalue_references.cpp
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

/**
 * @brief Explores lvalues, prvalues, and lvalue references in expressions.
 *
 * @details
 * - Variables are lvalues.
 * - Expressions like `2*a + b`, literals, function calls returning by value → prvalues.
 * - Lvalue references bind to lvalues; const lvalue references can bind to prvalues (via temporary materialization).
 */
int main()
{
    int a = 3, b = 2;
    int c = 2 * a + b;           // 2*a+b is prvalue
    const double D = sqrt(25.0); // sqrt(25.0) is prvalue
    string lang = "cpp";         // "cpp" is prvalue

    // lvalues: a, b, c, D, lang
    // prvalues: 3, 2, 2*a+b, "cpp", sqrt(25.0)

    // Non-const lvalue reference: binds only to modifiable lvalues
    int &ref1 = b;
    ref1 = 20; // OK: ref1 refers to 'b', which is addressable

    // ref1 + 1 is a prvalue (temporary) → cannot assign
    // ref1 + 1 = 4;  // CE

    // Const lvalue reference: can bind to const objects
    const int &ref2 = b;
    // ref2 = 20;  // CE: ref2 is const

    // Operators like '+' expect prvalues (implicit conversion from lvalue)
    c = a + b; // a and b converted to prvalues

    // Temporary objects (prvalues) have no name
    vector<int>(10); // prvalue: temporary vector
    double{};        // prvalue: temporary double initialized to 0.0

    cout << "a: " << a << ", b: " << b << ", c: " << c << endl;

    return 0;
}