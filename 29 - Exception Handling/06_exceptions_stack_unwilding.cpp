/**
 * @file 06_exceptions_stack_unwinding.cpp
 * @brief Stack unwinding: locals destroyed, heap leaks without RAII.
 *
 */

#include <iostream>
#include <stdexcept>

struct Employee
{
    int id;
    explicit Employee(int id_) : id(id_) {}
    ~Employee()
    {
        std::cout << "Destroy Employee " << id << "\n";
    }
};

void f4()
{
    std::cout << "Start f4\n";
    Employee *p = new Employee(4); /// Heap allocation
    throw 1;                       /// Exception thrown
    delete p;                      /// Never reached → LEAK!
    std::cout << "End f4\n";
}

void f3()
{
    std::cout << "Start f3\n";
    Employee local_emp(3);   /// Stack object
    f4();                    /// Throws → unwind starts
    std::cout << "End f3\n"; /// Skipped
}

void f2()
{
    std::cout << "Start f2\n";
    try
    {
        f3();
    }
    catch (const std::runtime_error &)
    {
        std::cout << "Wrong handler\n";
    }
    std::cout << "End f2\n";
}

void f1()
{
    std::cout << "Start f1\n";
    try
    {
        f2();
    }
    catch (int e)
    {
        std::cout << "Caught error code: " << e << "\n";
    }
    std::cout << "End f1\n";
}

int main()
{
    f1();
    return 0;
}