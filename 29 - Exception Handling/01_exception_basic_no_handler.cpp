/**
 * @file 01_exceptions_basic_no_handler.cpp
 * @brief Shows program termination when an exception is thrown but not caught.
 *
 * Key Lesson: Every `throw` must have a matching `catch` somewhere in the call stack.
 * Otherwise, `std::terminate()` is called.
 *
 */

#include <iostream>
#include <stdexcept>

struct BankAccount
{
    int money = 1000;

    /**
     * @brief Deducts bill from account.
     * @param bill_value Amount to pay.
     * @return true if successful.
     * @throws std::invalid_argument if negative.
     */
    bool PayBill(int bill_value)
    {
        /// Step 1: Validate input
        if (bill_value < 0)
            throw std::invalid_argument("Bill Value can't be negative!");

        /// Step 2: Check balance
        if (money >= bill_value)
        {
            money -= bill_value;
            return true;
        }
        return false;
    }
};

int main()
{
    /// Create a bank account with $1000
    BankAccount acct;

    /// Enable boolean output: true/false instead of 1/0
    std::cout << std::boolalpha;

    /// Call 1: Pay $100 → success (1000 >= 100)
    /// money becomes 900, returns true
    std::cout << acct.PayBill(100) << "\n"; // Output: true

    /// Call 2: Pay $500000 → failure (900 < 500000)
    /// No exception, just returns false
    std::cout << acct.PayBill(500000) << "\n"; // Output: false

    /// Call 3: Pay $-10 → throws invalid_argument
    /// No try/catch → exception propagates up
    /// Reaches main() → no handler → std::terminate()
    std::cout << acct.PayBill(-10) << "\n"; // Never executes

    /// This line is unreachable due to program termination
    std::cout << "This will never print.\n";

    return 0; // Never reached
}