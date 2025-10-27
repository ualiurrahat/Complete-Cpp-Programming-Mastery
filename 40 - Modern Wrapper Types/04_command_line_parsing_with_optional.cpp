// 04_command_line_parsing_with_optional.cpp
/**
 * @file 04_command_line_parsing_with_optional.cpp
 * @brief Parses command-line integers safely using std::optional.
 *
 * Real-world example: convert argv[] strings to int.
 * If conversion fails, return nullopt. Chain operations safely.
 * Only proceed if both arguments are valid.
 */

#include <iostream>
#include <optional>
#include <string>
using namespace std;

/**
 * @brief Attempts to parse a C-string into an integer.
 * @param arg Input string
 * @return optional<int>: contains parsed int on success, nullopt on failure
 *
 * Uses std::stoi in a try-catch. On failure (invalid format, out of range),
 * prints message and returns nullopt.
 */
optional<int> ParseInt(char *arg)
{
    try
    {
        return stoi(string(arg));
    }
    catch (...)
    {
        cout << "cannot convert '" << arg << "' to int!" << endl;
    }
    return {};
}

int main(int argc, char *argv[])
{
    if (argc >= 3)
    {
        auto oFirst = ParseInt(argv[1]);
        auto oSecond = ParseInt(argv[2]);

        // Only compute if both are valid
        if (oFirst && oSecond)
        {
            cout << "sum of " << *oFirst << " and " << *oSecond
                 << " is " << *oFirst + *oSecond << endl;
        }
        else
        {
            cout << "Need two valid integers!" << endl;
        }
    }
    else
    {
        cout << "Usage: program <num1> <num2>" << endl;
    }
    return 0;
}