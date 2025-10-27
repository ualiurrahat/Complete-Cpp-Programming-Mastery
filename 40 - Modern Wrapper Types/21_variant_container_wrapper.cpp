// 21_variant_container_wrapper.cpp
/**
 * @file 21_variant_container_wrapper.cpp
 * @brief A reusable wrapper around vector<variant<...>> with visit/push interface.
 *
 * Encapsulates heterogeneous storage and provides:
 * - `push_back`, `emplace_back`
 * - `visit(visitor)` to apply operation to all elements
 *
 * Generic over variant type → reusable for any set of types.
 */

#include <iostream>
#include <variant>
#include <vector>
using namespace std;

/**
 * @brief Container for heterogeneous variant objects.
 * @tparam VARIANT The variant type (e.g., variant<string, int>)
 */
template <class VARIANT>
struct VariantContainer
{
    vector<VARIANT> objects;

    /**
     * @brief Apply visitor to every element.
     * @tparam V Visitor type
     * @param visitor Callable with operator() for each variant type
     */
    template <class V>
    void visit(V &&visitor)
    {
        for (auto &object : objects)
            std::visit(visitor, object);
    }

    /**
     * @brief Add element by copy/move.
     */
    template <class V>
    void push_back(V &&item)
    {
        objects.push_back(forward<V>(item));
    }

    /**
     * @brief Construct element in-place.
     */
    template <class... Args>
    void emplace_back(Args &&...args)
    {
        objects.emplace_back(forward<Args>(args)...);
    }
};

int main()
{
    using VarType = variant<string, int>;

    VariantContainer<VarType> container;
    container.emplace_back("hello");
    container.emplace_back(1000);

    cout << "Container contents:\n";
    container.visit([](auto &&arg)
                    { cout << "  → " << arg << "\n"; });

    return 0;
}