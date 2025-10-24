/**
 * @file 07_ArrayOfObjectsUsingPointer.cpp
 * @brief Demonstrates dynamic allocation of array of objects using pointers in C++.
 *
 * Problem Statement:
 * - Create an array of objects dynamically using pointers.
 * - Take user input to set data for each object.
 * - Display stored information using object pointers.
 */

#include <iostream>
using namespace std;

class ShopItem
{
    int id;
    float price;

public:
    /// @brief Set product ID and price
    void setData(int a, float d)
    {
        id = a;
        price = d;
    }

    /// @brief Display product information
    void getData()
    {
        cout << "Product ID: " << id << endl;
        cout << "Product Price: " << price << endl;
    }
};

int main()
{
    // ---------------------- Dynamic Array of Objects ----------------------
    ShopItem *ptr = new ShopItem[3]; // Allocate array of 3 objects
    ShopItem *ptrTemp = ptr;         // Temporary pointer for traversal

    int p;
    float q;

    // ---------------------- Input Data ----------------------
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter ID of product " << i + 1 << ": ";
        cin >> p;
        cout << "Enter price for product " << i + 1 << ": ";
        cin >> q;
        ptr->setData(p, q);
        ptr++; // Move to next object
    }

    // ---------------------- Display Data ----------------------
    for (int i = 0; i < 3; i++)
    {
        ptrTemp->getData();
        ptrTemp++; // Move to next object
    }

    // Release allocated memory
    delete[] ptrTemp;

    return 0;
}
