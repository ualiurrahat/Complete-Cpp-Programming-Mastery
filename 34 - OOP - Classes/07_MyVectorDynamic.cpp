/**
 * @file 07_MyVectorDynamic.cpp
 * @brief Introduces dynamic memory allocation with RAII.
 *
 * - Constructor allocates an array of `int` using `new[]`
 * - All elements initialized to a user-provided default value
 * - Destructor uses `delete[]` → **no memory leaks**
 * - `get()` provides read access (no bounds checking for simplicity)
 *
 * This is a minimal educational version of `std::vector`.
 */

#include <iostream>
using namespace std;

class MyVector
{
private:
    int *arr; ///< Pointer to dynamically allocated array
    int len;  ///< Number of elements

public:
    /**
     * @brief Constructs a vector of given size, filled with a value.
     * @param length Size of the vector (must be > 0)
     * @param default_value Value to fill (default: 0)
     */
    MyVector(int length, int default_value = 0)
    {
        if (length <= 0)
        {
            cout << "Error: length must be positive!\n";
            len = 1;
        }
        else
        {
            len = length;
        }

        arr = new int[len]; // Allocate

        for (int i = 0; i < len; ++i)
        {
            arr[i] = default_value;
        }

        cout << "MyVector constructed with size " << len << "\n";
    }

    /** @brief Destructor – frees the dynamically allocated memory. */
    ~MyVector()
    {
        delete[] arr; // Deallocate
        cout << "MyVector destroyed (memory freed)\n";
    }

    /**
     * @brief Access element at index (read-only).
     * @param pos Index (0 to len-1)
     * @return Value at position
     */
    int get(int pos) const
    {
        if (pos < 0 || pos >= len)
        {
            cout << "Index out of bounds!\n";
            return -1;
        }
        return arr[pos];
    }

    /** @brief Returns the size of the vector. */
    int size() const { return len; }
};

int main()
{
    MyVector v(10, 12345);
    cout << "v[5] = " << v.get(5) << "\n"; // 12345
    cout << "Size: " << v.size() << "\n";

    // v is automatically destroyed here → memory freed
    return 0;
}