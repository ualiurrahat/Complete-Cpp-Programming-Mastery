/**
 * @file 02_cppProgramLifecycle.cpp
 * @brief Explains how a C++ program is written, compiled, and executed.
 *
 * @details
 * Before running a program, it's essential to understand what happens behind the scenes.
 * This file describes the life cycle of a C++ program — from writing source code to running the executable.
 */

// ---------------------- Theory: Program Life Cycle ----------------------
/*
    C++ Program Life Cycle has 4 stages:

    1️⃣ Write the Code:
        - The programmer writes the instructions using a programming language (C++).
        - These instructions are saved in a file, e.g., "hello.cpp".

    2️⃣ Compile the Code:
        - The compiler checks your code for syntax errors.
        - If there are mistakes (like missing semicolons, misspelled keywords), it reports them as *errors*.
        - If correct, it converts the code into *object code* (machine language).

    3️⃣ Linking:
        - The linker combines one or more object files into a single executable file (e.g., code.exe).
        - This file is something your computer's CPU can understand.

    4️⃣ Run the Program:
        - When you execute the file, the CPU follows your instructions step by step.
        - Output is displayed on the screen.
*/

// ---------------------- Theory: Compiler & Syntax ----------------------
/*
    ● Compiler:
        - A tool that translates your C++ source code (human-readable) into machine code (binary).

    ● Syntax:
        - The grammar rules of a programming language.
        - Example: Every statement must end with a semicolon `;`.

    ● If you make a syntax mistake:
        - The compiler stops and shows an *error* or *warning* message.

    ● If everything is correct:
        - The compiler generates object code files.
        - Then the *linker* creates an executable that your CPU can run.
*/

int main()
{
    // This file explains theoretical steps. Actual execution begins in the next file.
    return 0;
}
