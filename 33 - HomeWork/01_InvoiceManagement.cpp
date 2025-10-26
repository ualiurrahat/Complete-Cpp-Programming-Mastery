/**
 * @file 01_InvoiceManagement.cpp
 * @brief Homework: Design an Invoice class for item tracking.
 *
 * @section problem Problem Statement
 * Create a class `Invoice` to represent a single item in a store. Each item has:
 * - Item number (int)
 * - Name (string)
 * - Price per unit (double)
 * - Quantity (int, default = 1)
 *
 * The class must support:
 * - Getters and setters for all fields
 * - `GetTotalPrice()` → price × quantity
 * - `Print()` → formatted output
 * - `ToString()` → CSV-style string
 *
 * Use proper encapsulation and const-correctness.
 *
 * @section intuition Intuition
 * Real-world invoices need structured data with behavior.
 * Encapsulation ensures data integrity (e.g., negative quantity? → future validation).
 * `ToString()` enables logging/export. `Print()` is user-friendly.
 *
 * @section logic Logic & Flow
 * 1. Constructor initializes all fields
 * 2. Getters return values (by value or const ref)
 * 3. Setters update private members
 * 4. `GetTotalPrice()` computes on-the-fly (no stored total)
 * 5. `Print()` uses getters for consistency
 * 6. `ToString()` uses `ostringstream` for clean formatting
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Invoice
{
private:
    int item_number; ///< Unique identifier for the item
    string name;     ///< Item description
    double price;    ///< Price per unit
    int quantity;    ///< Number of units (default: 1)

public:
    /**
     * @brief Constructs an Invoice with given details.
     * @param item_number Unique ID
     * @param name Item name
     * @param price Price per unit
     * @param quantity Number of items (default 1)
     */
    Invoice(const int &item_number, const string &name,
            const double &price, const int &quantity = 1)
        : item_number(item_number), name(name), price(price), quantity(quantity) {}

    // === Getters ===
    int GetItemNumber() const { return item_number; }
    const string &GetName() const { return name; }
    double GetPrice() const { return price; }
    int GetQuantity() const { return quantity; }

    // === Setters ===
    void SetItemNumber(int itemNumber) { item_number = itemNumber; }
    void SetName(const string &name) { this->name = name; }
    void SetPrice(double price) { this->price = price; }
    void SetQuantity(int quantity) { this->quantity = quantity; }

    /**
     * @brief Calculates total cost.
     * @return double Total price = price × quantity
     */
    double GetTotalPrice() const
    {
        return price * quantity;
    }

    /// Prints invoice in readable format
    void Print() const
    {
        cout << "Item Name: " << name << "\n";
        cout << "Item Price: " << price << "\n";
        cout << "Item Quantity: " << quantity << "\n";
        cout << "Item Number: " << item_number << "\n";
        cout << "Item Total Price: " << GetTotalPrice() << "\n";
    }

    /**
     * @brief Returns CSV representation.
     * @return string Format: name,price,quantity,item_number
     */
    string ToString() const
    {
        ostringstream oss;
        oss << name << "," << price << "," << quantity << "," << item_number;
        return oss.str();
    }
};

int main()
{
    // Example usage (uncomment to test)
    /*
    Invoice inv(1001, "Laptop", 999.99, 2);
    inv.Print();
    cout << "CSV: " << inv.ToString() << "\n";
    */
    return 0;
}