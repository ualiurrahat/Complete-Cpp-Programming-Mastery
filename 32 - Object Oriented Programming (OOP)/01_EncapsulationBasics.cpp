/**
 * @file 01_EncapsulationBasics.cpp
 * @brief Introduces encapsulation using private/public members in a class.
 *
 * Encapsulation is a core OOP principle: bundling data and methods that operate
 * on that data within a single unit (class), while restricting direct access
 * to internal state.
 *
 * @section intuition Intuition
 * Think of a `Quote` object like a **safe**. The quote text is inside (private),
 * but you can still **use** it via a public method (`print()`). Direct access
 * to internal data is blocked — this prevents misuse and maintains integrity.
 *
 * @section logic Logic & Flow
 * 1. `internal` and `GetQuote()` are private → hidden from outside
 * 2. `external` and `print()` are public → accessible
 * 3. User can read `external`, call `print()`, but cannot touch internals
 *
 * @note This demonstrates **data hiding** — a foundation of secure design.
 */

#include <iostream>
#include <string>
using namespace std;

class Quote
{
private:
    int internal; ///< Hidden data — not accessible outside class

    /**
     * @brief Returns the motivational quote string.
     * @return std::string The quote text
     *
     * Private method: only class members can call it.
     */
    string GetQuote()
    {
        return "The way to get started is to "
               "quit talking and begin doing";
    }

public:
    int external; ///< Public data — can be accessed directly

    /// Default constructor initializes members
    Quote()
    {
        internal = 3;
        external = 7;
    }

    /// Public method to display the quote
    void print()
    {
        cout << GetQuote() << "\n";
    }
};

int main()
{
    Quote q;

    // Public member: direct access allowed
    cout << q.external << "\n";

    // Public method: can be called
    q.print();

    // q.internal;     // ERROR: private
    // q.GetQuote();   // ERROR: private

    return 0;
}