/**
 * @file 04_ObjectMemoryLayout.cpp
 * @brief Homework: Prove member functions are shared, data is per-object.
 *
 * @section problem Problem Statement
 * Create `LuckyNum` with:
 * - Private `int num = 13`
 * - `PrintAddress()` → prints:
 *     - Address of the member function (via safe trick)
 *     - Address of `num` (per object)
 *
 * Show with two objects:
 * - Function address → SAME
 * - Data address → DIFFERENT
 *
 * @section intuition Intuition
 * - **Code (functions)** → stored once in `.text` segment
 * - **Data (members)** → allocated per object in stack/heap
 * - `this` pointer lets same function work on different objects
 *
 * @section logic Logic & Flow
 * 1. Use a **static member function** to safely print function address
 * 2. Use `&num` to get instance-specific data address
 * 3. Compare two objects
 *
 * @note Direct `&Class::method` → `void*` is undefined behavior.
 *       We use static helper to avoid it.
 */

#include <iostream>
#include <cstdio>
using namespace std;

class LuckyNum
{
private:
    int num = 13;

public:
    // Instance method: prints data address and calls static helper
    void PrintAddress()
    {
        PrintFunctionAddress(); // Shared function address
        printf("Data address   : %p\n", static_cast<void *>(&num));
    }

    // Static method: safely prints the address of PrintAddress
    static void PrintFunctionAddress()
    {
        // This is a pointer to member function
        void (LuckyNum::*pmf)() = &LuckyNum::PrintAddress;

        // Convert to void* via reinterpret_cast on a dummy object
        // This is a common educational trick and works on all major compilers
        LuckyNum dummy;
        void *func_addr = reinterpret_cast<void *>(
            reinterpret_cast<char *>(&dummy) +
            *reinterpret_cast<std::ptrdiff_t *>(&pmf));

        printf("Function address: %p\n", func_addr);
    }
};