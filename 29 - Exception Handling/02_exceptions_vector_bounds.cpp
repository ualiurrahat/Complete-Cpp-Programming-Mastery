/**
 * @file 02_exceptions_vector_bounds.cpp
 * @brief Compares operator[] (unsafe) vs .at() (safe with exception).
 *
 */

#include <iostream>
#include <vector>

int main()
{
    /// Create vector of 10 integers → valid indices: 0 to 9
    std::vector<int> v(10);

    std::cout << "=== Unsafe access with operator[] ===\n";
    /// v[25] is OUT OF BOUNDS!
    /// operator[] does NOT check bounds → Undefined Behavior (UB)
    /// May read garbage, crash, or appear to work
    int t = v[25];
    std::cout << "v[25] gave: " << t << "\n"; // Garbage value

    std::cout << "\n=== Safe access with .at() ===\n";
    try
    {
        /// .at(25) checks bounds → throws std::out_of_range
        t = v.at(25);
        std::cout << "This line won't run.\n";
    }
    catch (const std::out_of_range &e)
    {
        /// Exception caught here
        std::cout << "Caught: " << e.what() << "\n";
        /// Program continues normally after catch
    }

    /// Execution resumes here after handling exception
    std::cout << "Program continues safely.\n";

    return 0;
}