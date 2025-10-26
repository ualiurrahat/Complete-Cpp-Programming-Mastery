/**
 * @file 02_ParseStringAndInteger.cpp
 * @brief Parses a string path and integer limit from command-line arguments.
 *
 * This program expects exactly two arguments:
 * 1. A string (e.g., file path)
 * 2. An integer (e.g., size limit)
 *
 * It demonstrates:
 * - Argument count validation
 * - String-to-integer conversion using stringstream
 * - Basic error handling with user feedback
 *
 * @section intuition Intuition
 * Real programs often need structured input: paths, numbers, flags, etc.
 * Raw `argv[]` gives strings only — we must **convert** them safely.
 * Using `istringstream` is safer than `atoi()` because:
 * - It respects C++ type system
 * - Allows validation (though basic here)
 * - Integrates well with streams
 *
 * This builds on 01 — now we **interpret** arguments, not just print them.
 *
 * @section logic Logic & Flow
 * 1. Check if at least 3 arguments exist (program + 2 inputs)
 * 2. If not, print error and exit early
 * 3. Extract:
 *    - argv[1] → string `path`
 *    - argv[2] → convert to int via helper function `toint()`
 * 4. Echo both values to confirm parsing
 *
 * @note In production, add robust validation (e.g., check conversion success).
 */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/**
 * @brief Converts a string to integer using stringstream.
 *
 * @param str Input string containing integer
 * @return int Parsed integer value
 *
 * @note No error checking — assumes valid input.
 *       In robust code, check `iss.fail()` after extraction.
 */
int toint(string str)
{
    istringstream iss(str); // Create input string stream from string
    int ret;                // Variable to hold result
    iss >> ret;             // Extract integer from stream
    return ret;             // Return parsed value
}

int main(int argc, char *argv[])
{
    // Validate minimum required arguments: program + path + limit
    if (argc < 3)
    {
        cout << "ERROR: Please pass string and integer\n";
        cout << "Usage: " << argv[0] << " <path> <limit>\n";
        return 0; // Exit gracefully on error
    }

    // Extract first argument as string (file path or any text)
    string path = argv[1];

    // Convert second argument from string to integer
    int limit = toint(argv[2]);

    // Output parsed values for verification
    cout << path << "\n";
    cout << limit << "\n";

    return 0; // Success
}