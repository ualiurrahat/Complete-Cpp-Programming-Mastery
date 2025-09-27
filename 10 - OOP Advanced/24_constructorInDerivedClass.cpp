/*
Problem Statement:

Constructors in Derived Classes in C++

- Constructors can be used in derived classes.
- If the base class constructor has no arguments, there is no need to explicitly define a constructor in the derived class.
- If the base class constructor requires arguments, the derived class must pass arguments to it.
- When both base and derived classes have constructors:
    - Base class constructor executes first.
    - Then the derived class constructor executes.

Special Notes on Inheritance:
1. In Multiple Inheritance:
   - Base class constructors are executed in the order in which they are declared in the derived class.
   Example:
        class C : public A, public B;  // A() runs first, then B()
        class C : public B, public A;  // B() runs first, then A()

2. In Multilevel Inheritance:
   - Constructors are executed in the chain of inheritance.
   Example:
        A --> B --> C
        Execution order: A(), B(), then C()

Special Syntax:
DerivedConstructor(args) : Base1Constructor(arg1), Base2Constructor(arg2) {
    // body of derived constructor
}

Special Case of Virtual Base Classes:
- Constructors for virtual base classes are invoked before non-virtual base classes.
- If multiple virtual base classes exist, they are called in the order of declaration.
*/
