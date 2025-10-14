/**
 * @file 03_myFirstProgram.cpp
 * @brief Writing and understanding your first C++ program.
 *
 * @details
 * In this file, we will write a simple program to display a message on the screen.
 * We will then discuss each line to understand how C++ works.
 */

#include <iostream>  // Header file for input and output (I/O) operations.
using namespace std; // Gives access to standard C++ names like 'cout' and 'cin'.

/**
 * @brief The main entry point of a C++ program.
 *
 * @return int Returns 0 when the program executes successfully.
 *
 * @note Time complexity: O(1)
 * @note Space complexity: O(1)
 */
int main()
{
    // ---------------------- Printing Output ----------------------
    /*
        The command below displays text on the screen.
        - `cout` stands for "console output" — it sends data to the display screen.
        - The operator `<<` sends (inserts) data into the output stream.
        - The text must be enclosed in double quotes "".
        - Each statement must end with a semicolon `;`.
    */
    cout << "My First Program. Helllllllo.";

    // ---------------------- Explanation of Components ----------------------
    /*
        ✅ #include <iostream>
            - Tells the compiler to include the Input/Output Stream library.
            - It allows using `cout` (for output) and `cin` (for input).

        ✅ using namespace std;
            - `std` means "standard".
            - It is a collection of all standard C++ names.
            - Without this line, we would need to write `std::cout` instead of `cout`.

        ✅ int main()
            - Every C++ program must have a main() function.
            - The program starts executing from here.
            - 'int' means this function returns an integer value.

        ✅ return 0;
            - Means the program ended successfully.
            - If we wrote `return 1;`, it would mean the program ended abnormally.
    */

    return 0; // End of main function
}

/*
---------------------- Summary ----------------------

1️⃣ Header Files (#include):
    Contain pre-written functions (e.g., for math, input, output).

    Examples:
        - #include <iostream> → for input/output (cout, cin)
        - #include <cmath>    → for mathematical operations (sqrt, pow, etc.)

2️⃣ main() Function:
    The starting point of every program.

3️⃣ cout and <<:
    Used to print data to the console.

4️⃣ Semicolon (;):
    Ends each C++ statement (like a full stop in English).

-----------------------------------------------------
*/
