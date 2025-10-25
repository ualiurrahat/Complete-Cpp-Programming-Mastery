/**
 * @file 07_exceptions_raii_demo.cpp
 * @brief RAII prevents leaks using std::unique_ptr.
 *
 */

#include <iostream>
#include <memory>
#include <stdexcept>

struct Employee
{
    int id;
    explicit Employee(int id_) : id(id_) {}
    ~Employee() { std::cout << "Destroy Employee " << id << "\n"; }
};

void f4()
{
    std::cout << "Start f4\n";
    auto p = std::make_unique<Employee>(4); /// RAII: owns pointer
    throw 1;                                /// Exception
    /// p automatically deleted in scope exit
}

void f3()
{
    std::cout << "Start f3\n";
    Employee local(3);
    f4();
}

int main()
{
    try
    {
        f3();
    }
    catch (int e)
    {
        std::cout << "Caught: " << e << "\n";
    }
    return 0;
}