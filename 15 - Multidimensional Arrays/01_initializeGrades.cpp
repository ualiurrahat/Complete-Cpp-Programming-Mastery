/**
 * @file 01_initializeGrades.cpp
 * @brief Initialize a 2D array (grades) and show how to assign values manually.
 *
 * Problem:
 * Demonstrate declaring and initializing a 2D array (matrix) for storing
 * student grades. Show how to set values for specific students and subjects.
 *
 * Notes:
 * - This file focuses only on initialization and explicit assignment.
 * - Follow-up files will demonstrate reading, printing and processing the matrix.
 *
 * Example (partial):
 * We have 7 students (rows) and 6 grade slots (columns) but only first 4 columns are used here.
 *
 * Expected short output (when printing values):
 * Row 0: 50 33 40 30 0 0
 * Row 1: 35 50 40 30 0 0
 * ...
 * Row 6: 35 30 47 16 0 0
 */

#include <iostream> // cout, endl
using namespace std;

int main()
{
    // Declare a 2D array of 7 rows and 6 columns.
    // Using initializer {0} sets all elements to 0 (zero-initialize).
    // Type: double to allow fractional grades if needed later.
    double grades[7][6] = {0};

    /**********************************************************************
     * Important note about memory & layout:
     * - `grades` is allocated on the stack (fixed-size array).
     * - Elements are stored in row-major order: grades[row][col] memory
     *   is laid out as row 0's columns, then row 1's columns, etc.
     *
     * Row-major matters when accessing the array (cache-friendliness).
     *********************************************************************/

    // -------------------------
    // Manually assign grades
    // -------------------------
    // Each line below assigns four subject scores for a particular student.
    // We keep the original variable names / comments for clarity.

    // Mostafa Grades (student at row 0)
    // We assign only first 4 columns; other columns remain 0 from initialization.
    grades[0][0] = 50; // Mostafa subject 0
    grades[0][1] = 33; // Mostafa subject 1
    grades[0][2] = 40; // Mostafa subject 2
    grades[0][3] = 30; // Mostafa subject 3

    // Asmaa Grades (student at row 1)
    grades[1][0] = 35; // Asmaa subject 0
    grades[1][1] = 50; // Asmaa subject 1
    grades[1][2] = 40; // Asmaa subject 2
    grades[1][3] = 30; // Asmaa subject 3

    // ... (other students would be filled similarly)
    // For the example we skip rows 2..5 to mimic partial data entry.

    // Mona Grades (student at row 6)
    grades[6][0] = 35; // Mona subject 0
    grades[6][1] = 30; // Mona subject 1
    grades[6][2] = 47; // Mona subject 2
    grades[6][3] = 16; // Mona subject 3

    /**********************************************************************
     * Why use explicit assignments instead of an initializer list?
     * - Explicit assignments are easy to follow in teaching examples.
     * - They show how to address by row and column indexes.
     *
     * In production code, prefer:
     *   - initializer lists for small fixed matrices, or
     *   - loops/inputs for larger or dynamic data.
     *********************************************************************/

    // Minimal print-out to demonstrate initialization (keeps file focused).
    // Print all rows and columns (0..5) so reader can observe zeros in unused columns.
    cout << "Grades matrix after manual assignments (7 rows x 6 cols):" << endl;
    for (int row = 0; row < 7; ++row)
    {
        cout << "Row " << row << ": ";
        for (int col = 0; col < 6; ++col)
        {
            // Print each element followed by a space.
            cout << grades[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Time Complexity:
- Initialization (double grades[7][6] = {0}) is O(1) from programmer view (compiler zero-initializes).
- Printing loop is O(R * C) where R = 7, C = 6 (here constant → O(1) practically).

Space Complexity:
- O(R * C) = O(7*6) = O(42) doubles on the stack.
  (In general, for a RxC fixed-size array it's O(R*C).)
*/
