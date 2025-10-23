/**
 * @file 20_VariadicVectorPushBack.cpp
 * @brief Demonstrates fold expressions for vector operations.
 * 
 * This file uses a comma operator in a fold expression to push multiple elements into a vector.
 * 
 * New Topics Introduced:
 * - **Comma Operator in Fold Expressions**: Using `,` to execute multiple operations (e.g., `push_back`) in a fold expression.
 * - **Right Fold Expansion for Comma Operator**: The fold expression `(v.push_back(args), ...)` expands to execute `push_back` for each argument.
 * - **Variadic Function Composition**: Passing a parameter pack to another variadic function.
 * 
 * The `push_back_vec` function uses a fold expression to push arguments into a vector, and `PassPack` demonstrates forwarding a parameter pack.
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Pushes arguments into a vector using a fold expression.
 * @tparam T Type of the vector elements.
 * @param v Vector to push elements into.
 * @param args Arguments to push into the vector.
 */
template<typename T>
void push_back_vec(vector<T>& v, auto... args) {
    (v.push_back(args), ...); // Right fold: v.push_back(arg0), v.push_back(arg1), ...
}

/**
 * @brief Forwards a parameter pack to push_back_vec.
 * @tparam T Type of the vector elements.
 * @param v Vector to push elements into.
 * @param args Arguments to forward.
 */
template<typename T>
void PassPack(vector<T>& v, auto... args) {
    push_back_vec(v, args...); // Forward parameter pack
}

/**
 * @brief Main function to test vector push_back with fold expressions.
 * @return int Program exit status.
 */
int main() {
    vector<int> v;
    PassPack(v, 10, 20, 30); // Push 10, 20, 30 into vector
    for (const auto& x : v) {
        cout << x << " "; // Outputs: 10 20 30
    }
    return 0;
}