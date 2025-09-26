/**
 * @file 03_memoryAllocationInClass.cpp
 * @brief Demonstrates Memory Allocation and Arrays in Classes.
 *
 * Memory Allocation in Classes:
 * ------------------------------
 * - Variables (data members) are allocated memory when an object is created.
 *   Each object gets its own copy of variables.
 * - Functions (member functions) are allocated memory only once, shared by all objects.
 *
 * Example:
 * - Shop class stores multiple items with IDs and prices.
 * - Demonstrates how arrays can be used inside a class.
 */

#include <iostream>
using namespace std;

class Shop
{
    int itemID[100];    ///< Array to store item IDs
    int itemPrice[100]; ///< Array to store item prices
    int counter;        ///< Tracks number of items entered

public:
    /// Initializes counter to 0
    void initCounter()
    {
        counter = 0;
    }

    /// Reads item ID and price from user
    void getPrice();

    /// Displays all items with their prices
    void displayPrice();
};

void Shop::getPrice()
{
    cout << "Enter ID of item no " << counter + 1 << ": ";
    cin >> itemID[counter];

    cout << "Enter price for item: ";
    cin >> itemPrice[counter];

    counter++;
}

void Shop::displayPrice()
{
    cout << "\n----- Item List -----\n";
    for (int i = 0; i < counter; i++)
    {
        cout << "Item ID " << itemID[i]
             << " has price: " << itemPrice[i] << " Taka" << endl;
    }
}

int main()
{
    Shop Agora;          // Create object
    Agora.initCounter(); // Initialize counter

    // Input 3 items
    Agora.getPrice();
    Agora.getPrice();
    Agora.getPrice();

    // Display items
    Agora.displayPrice();

    return 0;
}
