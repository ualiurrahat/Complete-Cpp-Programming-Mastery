/**
 * @file 05_exceptions_rethrow.cpp
 * @brief Use `throw;` to rethrow current exception.
 *
 */

#include <iostream>
#include <stdexcept>

struct BankAccount
{
    int money = 1000;
    bool PayBill(int bill_value)
    {
        if (bill_value < 0)
            throw std::invalid_argument("Bill Value can't be negative!");
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
    BankAccount acct;
    std::cout << std::boolalpha;

    try
    {
        /// Normal payments
        std::cout << acct.PayBill(100) << "\n";    // true
        std::cout << acct.PayBill(500000) << "\n"; // false

        /// This throws
        std::cout << acct.PayBill(-10) << "\n";

        /// Unreachable
        std::cout << acct.PayBill(200) << "\n";
    }
    catch (const std::invalid_argument &e)
    {
        /// Log the error
        std::cout << "Caught in main: " << e.what() << "\n";

        /// Rethrow same exception
        throw; // No argument → rethrows current exception
    }

    /// Never reached
    std::cout << "This line is never reached.\n";
    return 0;
}